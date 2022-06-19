.model tiny
.386
 
.code
    org 80h         
    COMAND_LENGHT db ?      
    COMAND_LINE db ?        
    org 100h 
    
 
 
    
start:
    cld
    mov cl, COMAND_LENGHT
    cmp cl, 1         
    jle BAD_PARAMETRES        
 
    mov cx, -1
    mov di, offset COMAND_LINE    
         
    mov al, ' '
    repz scasb
    dec di  
    inc argc
    mov si,di       
READ_PARAMETRES:
    lodsb           
    cmp al, 0Dh      
    je END_PARAMETRES
    cmp al, 20h      
    jne READ_PARAMETRES
    dec si
    mov byte ptr [si], 0    
    mov di,si
    inc di  
 
END_PARAMETRES:
    dec si
    mov byte ptr [si], 0
    cmp argc, 1
    jne BAD_PARAMETRES
 
    mov [NUMBER_OF_STRING], 0
 
    mov [MAX_NUMBERS],0
    
    CLEAR_PATH:
    mov si,0
    WHILE:
    mov byte ptr[PATH_TO_RUNNING+si],""
    mov byte ptr[BUFFER+si],""
    inc si
    cmp si,80
    je FINDED_PARAMETRES
    jmp WHILE
    FINDED_PARAMETRES:
    call FOPEN
    call READ_FILEPATH
    call FCLOSE
    
    mov sp, PROGRAM_LENGHT+100h + 200h  
    
    mov ah, 4Ah     
    stack_offset = PROGRAM_LENGHT + 100h + 200h     
    mov bx, stack_offset shr 4 + 1                  
    int 21h
    jnc INITIALIZE_EPB
    lea dx, ERROR
    mov ah, 9
    int 21h
    inc byte ptr [MAX_NUMBERS]
    mov ah, [MAX_NUMBERS]
    mov [NUMBER_OF_STRING], ah
    jmp CLEAR_PATH
INITIALIZE_EPB:
    mov ax,cs                   
    mov word ptr EPB+4, ax          ;cmd
    
    xor cx, cx
    mov cl, 1  
    
MAIN_CYCLE:
    mov ax, 4B00h   
    mov dx, offset PATH_TO_RUNNING
    mov bx, offset EPB      
    int 21h
    
    jnc RUN_NEXT            
    mov ah,9
    lea dx, ERROR
    int 21h
RUN_NEXT:
    inc byte ptr [MAX_NUMBERS]
    mov ah, [MAX_NUMBERS]
    mov [NUMBER_OF_STRING], ah
    jmp CLEAR_PATH
    loop MAIN_CYCLE
    
    
EXIT:
    int 20h 
 
BAD_PARAMETRES:
    mov dx, offset ERROR_PARAMS
    mov ah, 9
    int 21h
    int 20h 
 
CHECK_CURRENT:
    
    mov di, offset COMAND_LINE + 1
    lea si, NAME_CURRENT
    xor cx, cx
    mov cx, 8
    looop:
        mov bx, [di]
        mov dx, [si]
        cmp bx, dx
        jne end_check 
        inc si
        inc di
        loop looop
    wrong:
        lea dx, ERROR_CURRENT
        xor ax, ax
        mov ah, 9
        int 21h
        int 20h
    end_check:
    jmp CURRENT_BACK
 
 
 
FOPEN proc 
    push dx
    push ax
    mov dx,offset COMAND_LINE + 1 
    pusha
    jmp CHECK_CURRENT
    CURRENT_BACK:
    popa
    mov ah, 3Dh  
    mov al, 00h             
    int 21h
    
    jnc GOOD_OPEN           ;if cf == 1 ERROR
    lea dx, ERROR_OPENING
    mov ah, 9
    int 21h
    mov ax, 4C00h        
    int 21h   
 
GOOD_OPEN:
    mov [FILE_DESCRIPTOR], ax
    pop ax
    pop dx
    ret
FOPEN endp 
 
READ_FILEPATH proc 
    mov di, offset PATH_TO_RUNNING
END_LINE:
    cmp byte ptr [NUMBER_OF_STRING], 0
    jle CURRENT_LINE    
    dec byte ptr [NUMBER_OF_STRING]
READ_CYCLE:
    mov ah, 3fh                 
    mov bx, [FILE_DESCRIPTOR]
    mov cx, 1
    lea dx, [BUFFER]        
    int 21h
    cmp ax, 0
    je FILE_END
    cmp byte ptr [BUFFER], 0Ah
    jne READ_CYCLE
 
    jmp END_LINE
    
FILE_END:
    call FCLOSE
    int 20h
    
CURRENT_LINE:
    mov ah, 3fh                 
    mov bx, [FILE_DESCRIPTOR]
    mov cx, 80
    lea dx, [BUFFER]        
    int 21h
    cmp ax, 0
    je EXIT_FROM_FINDING
    lea si, BUFFER
    mov cx, 80
CURRENT_LINE_LOOP:  
    lodsb
    cmp al, 0Dh
    je EXIT_FROM_FINDING
    stosb
    loop CURRENT_LINE_LOOP
    
EXIT_FROM_FINDING:  
 
    ret
READ_FILEPATH endp
 
 
FCLOSE proc 
    mov ah, 3Eh
    mov bx, [FILE_DESCRIPTOR]
    int 21h
    ret
FCLOSE  endp 
 
 
PATH_TO_RUNNING db 20 dup(0)
BUFFER db 80 dup(0)
FILE_DESCRIPTOR dw 0    
ERROR_OPENING db 'ERROR with opening the file with entered name!', 0Dh, 0Ah, '$'
ERROR_PARAMS db 'ERROR in comand line params and try again!', 0Dh, 0Ah, '$' 
NAME_CURRENT db "lab7_1.com"
ERROR_CURRENT db 0Dh, 0Ah, "ERROR: you can't open this program", 0Dh, 0Ah, '$'
NUMBER_OF_STRING db 20 dup('$')
MAX_NUMBERS db 20 dup('$')
argc db 0 
 
 
ERROR       db "ERROR in running program ",10,13,'$'     
EPB         dw 0000                         
            dw offset CMD_LINE, 0        
            dd 0                            
            dd 0                            
 
CMD_LINE db 5                           
            db " /?"                        
            db 2 dup(?)                     
PROGRAM_LENGHT equ $-start                  
 
end start