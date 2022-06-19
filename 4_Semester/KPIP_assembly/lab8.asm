code    segment                          ; определение кодового сегмента
        assume  cs:code                  ; CS указывает на сегмент кода
        org     100h                     ; размер PSP для COM программы
.386
start:  jmp     load                     ; переход на нерезидентную часть
        old     dd  0                    ; адрес старого обработчика 
        buf     db  ' 00:00:00 ',0       ; шаблон для вывода текущего времени
        scrpos  dw 0
        in_mem  db   "Already in memmory$"
        error_mes db "Incorrect params :(", 0Dh, 0Ah, '$'
 
decode  proc                             ; процедура заполнения шаблона
        mov     ah,  al                  ; преобразование двоично-десятичного 
        and     al,  15                  ; числа в регистре AL
        rept 4
        shr     ah,  1                   ; в пару ASCII символов
        endm
        add     al,  '0'
        add     ah,  '0'
        mov     buf[bx + 1],  ah         ; запись ASCII символов
        mov     buf[bx + 2],  al         ; в шаблон
        add     bx,  3      
        ret                              ; возврат из процедуры
decode  endp                             ; конец процедуры 
 
clear proc near
            mov         ah,0
            mov         al,3
            int         10h  
            mov         ah,02
            mov         dh,0
            mov         dl,0
            int         10h
            ret
clear endp
 
; Resident part
label_tsr   dw  0AAAAh
clock   proc                             ; процедура обработчика прерываний от таймера
        CLI
        
        push        ds
        push        cs
        pop         ds
 
        pusha
        pushf 
 
        call    dword ptr cs:old                   ; вызов старого обработчика прерываний
        
        cmp     dl, 0ffh
        jz      off_clock
        
        mov     ah,  2                   ; функция BIOS для получения текущего времени
        int     1Ah                      ; прерывание BIOS
 
        xor     bx,  bx                  ; настройка BX на начало шаблона
        mov     al,  ch                  ; в AL - часы
        call    decode                   ; вызов процедуры заполнения шаблона - часы
        mov     al,  cl                  ; в AL - минуты
        call    decode                   ; вызов процедуры заполнения шаблона - минуты
        mov     al,  dh                  ; в AL - секунды
        call    decode                   ; вызов процедуры заполнения шаблона - секунды 
 
        mov     ax,  0B800h              ; настройка AX на сегмент видеопамяти
        mov     es,  ax                  ; запись в ES значения сегмента видеопамяти
        mov     di,  scrpos              ; настройка DI на адрес видеопамяти
        xor     bx,  bx                  ; настройка BX на начало шаблона
        mov     ah,  1fh;1000 1011       ; атрибут выводимых символов
@@1:    mov     al,  buf[bx]             ; цикл для записи символов шаблона в видеопамять
        stosw                            ; запись очередного символа и атрибута
        inc     bx                       ; инкремент указателя на символ шаблона
        cmp     buf[bx],  0              ; пока не конец шаблона,
        jnz     @@1                      ; продолжать запись символов
        jmp     @@5
        
off_clock:  cli
            mov     ds, word ptr cs:old+2
            mov     dx, word ptr cs:old
            mov     ax, 251Ch
            int     21h
            call clear
            sti
@@5:    
        popa
        pop         ds   
        sti
        iret                             ; возврат из обработчика
clock   endp                             ; конец процедуры обработчика
end_clock:                               ; метка для определения размера резидентной
                                         ; части программы
    posx    db 0
    posy    db 0
 
puts macro str
    push ax
    push dx
    lea dx, str
    mov ah, 9
    int 21h
    pop dx
    pop ax    
endm
 
load:   
    mov     ax, 351Ch
    int     21h
    mov     ax, es:[bx-2]
    cmp     ax, cs:label_tsr
    jnz     _land                   ; Если прерывание ещё не переопределено
                                    ; В противном случае    
    mov     dl, 0ffh
    int     1ch
    
    jmp     _end_prog
    
    _land:                          ; Прыгаем на блок посадки
    mov     si,5Dh                  ; адрес 1го числа
    call    readval                 ; преобразовать текст в число
    mov     posx,al
 
    mov     si,6Dh                   ; адрес 2го числа
    call    readval          ; преобразовать текст в число
    mov     posy,al
    
    cmp     posx,69+1
    jc      m3
    mov     posx,69
 
m3:     
    cmp     posy,24+1
    jc      m4
    mov     posy,24
m4:    
    mov     al,posy ; ax=80*posy+posx
    mov     bh,80
    mul     bh
    add     al,posx
    adc     ah,0
    add     ax,ax  ; ax=ax*2
    mov     scrpos,ax            ; видео адрес для изображения часов
    
    cli
    mov         ah, 35h
    mov         al, 1Ch
    int         21h
    mov         word ptr cs:old, bx
    mov         word ptr cs:old+2, es
    
    ; Set inter. address.. 
    mov         ah, 25h
    mov         al, 1Ch
    lea         dx, clock
    int         21h
    lea         dx, end_clock
    
    sti
    int         27h
isdigit: 
    cmp bl,"0"
    jc notdigit
    cmp  bl,"9"+1
    jnc notdigit
    clc
    ret
notdigit:
    puts error_mes
    jmp _end_prog
    ;stc
    ret
 
readval:
    mov     cx,2       ; предполагается не более 2 цифр
    mov     ax,0
m0:
    mov     bl,ds:[si]
    inc     si
    call    isdigit   ; это цифра ?
    jc      m1
    sub bl, "0"        ; да
    mov     bh,10     ; ax=al*10+bl
    mul     bh
    add     al,bl
m1:
    loop    m0
    ret
 
_end_prog:
    mov     ax, 4C00h
    int     21h
code    ends                             ; конец кодового сегмента
        end     start                    ; конец программы