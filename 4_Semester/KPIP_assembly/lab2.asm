                            .model small
.stack 100h
 
.data
 
enter_message db "Input string", 0Ah, 0Dh, '$'
string db 205 dup ('$')
user_str_message db 0Ah, 0Dh, "Your string", 0Ah, 0Dh, '$'
end_message db 0Ah, 0Dh, "Final string", 0Ah, 0Dh, '$'
end_of_word dw 0
 
 
.code
 
output_str macro get_str
    mov AH, 9h
    mov DX, offset get_str
    int 21h
endm
 
start:
    mov AX, @data
    mov ds, AX
    mov ah, 9
    mov dx, offset enter_message
    int 21h
    mov CX, 200
    xor SI, SI
    lea SI, string
    JMP input_string
 
input_string:
 
    mov AH, 1h
    int 21h
    mov [SI], AL
    mov AH, 0Dh
    cmp AL, AH
    JE continue_program
    inc SI
    loop input_string
    lea SI, string
 
continue_program:
 
output_str user_str_message
output_str string 
lea SI, string   
;mov AX, SI
;mov DX, DI 
 
 
firstCycle:
     lea DI, [SI]
     mov AX, SI
;mov DX, DI 
     ;lea AX, DI
     JMP isEndDI
 
    secondCycle:         
        ;inc DI  
        ;inc DX
        
        inc DI
        xor BH,BH
        xor BL,BL
        
        mov BH, [SI]
        mov BL, [DI] 
        
        cmp BL, '$'
        JE isEndDI
        
        ;cmp BL, 13
        ;JE isEndDI
        
        
        cmp BH, BL
        JG reverse
        JLE isEndDI
 
 
 
 
 
 
finish:                            
    output_str end_message
    output_str string
    mov AX, 4C00h
    int 21h         
 
 
isEndDI:   
    xor BH,BH
    mov BH, [DI]
    cmp BH, '$'
    JE  isEndSI  
    JNE isEnterDI
 
isEnterDI:
    xor BH,BH
    mov BH, [DI]
    cmp BH, 13
    JE  isEndSI
    JNE isNewWordDI
 
isNewWordDI:
    xor BH,BH
    mov BH, [DI]
    cmp BH, 32
    JE secondCycle
    JNE goDIToSpace
 
goDIToSpace:
    inc DI
    JMP isEndDI   
 
isEndSI:   
    xor BH,BH
    mov BH, [SI]
    cmp BH, '$'
    JNE  isEnterSI
    JE   finish  
 
isEnterSI:  
    xor BH,BH
    mov BH, [SI]
    cmp BH, 13
    JE   finish
    JNE  isSpaceSI 
 
isSpaceSI: 
    xor BH,BH
    mov BH, [SI]
    cmp BH, 32
    JE   beginOfTheWordSI 
    JNE  incSI
 
 
 
incSI:
    inc SI
    JMP isEndSI
 
 
beginOfTheWordSI:
    inc SI
    JMP firstCycle 
 

 
reverse:
    ;dec DI
     JMP goToTheNextWord
     decDI:
        dec DI
  
    xor AL,AL
    xor DL,DL
    lea AX, [SI]
    lea DX, [DI]
    mov CX, 4
    JMP indexCompare  
    
    
    
    
goToTheNextWord:

    isEndDIinCycle:   
        xor BH,BH
        mov BH, [DI]
        cmp BH, '$'
        JE  decDI  
        JNE isEnterDIinCycle
 
    isEnterDIinCycle:
        xor BH,BH
        mov BH, [DI]
        cmp BH, 13
        JE  decDI
        JNE isNewWordDIinCycle
 
    isNewWordDIinCycle:
        xor BH,BH
        mov BH, [DI]
        cmp BH, 32
        JE decDI
        JNE goDIToSpaceinCycle
     
    goDIToSpaceinCycle:
        inc DI
        JMP isEndDIinCycle   
 
        
    
    
    
    
    
 
indexCompare:
    cmp CX, 4
    JE  DecCX
    cmp CX, 3
    JE  swapFirstWord   
    cmp CX, 2
    JE  swapLastWord
    cmp CX, 1
    JE  swapMiddle
    cmp CX, 0
    JE  shiftBorders
                      
                      
shiftBorders:
    ;lea SI, [AX]
    ;lea DI, [DX]
    ;inc DX                      
    mov SI, AX
    mov DI, DX
    inc DI                 
    JMP secondCycle                  
                      
                      
 
DecCX:
    dec CX
    JMP Compare  
    
     
Compare:
    ;xor BH, BH
    ;xor BL, BL 
    ;mov BH, [SI]
    ;mov BL, [DI]
    cmp SI, DI
    JL  swap
    JGE indexCompare    
    
    
 
swapFirstWord:
    ;xor AL, AL
    ;xor DL, DL
    
    mov SI, AX
    mov DI, AX 
    
    ;mov AX, [SI]
    ;mov DX, [SI]
    JMP whileNoSpace     
    

 
whileNoSpace:
    xor BL, BL
    mov BL, [DI]
    cmp BL, 32
    JNE incDI
    dec DI
    JMP DecCX
 
                                       
 
incDI:
    inc DI
    JMP whileNoSpace    
    

swapLastWord:
   ; xor AL, AL
   ; xor DL, DL
    
    mov DI, DX
    mov SI, DX 
    
    ;mov AL, [DI]
    ;mov DL, [DI]
    JMP moveBackSI
 
moveBackSI:
    xor BL, BL
    mov BL, [SI]
    cmp BL, 32
    JNE decSI
    inc SI
    JMP DecCX
 
decSI:
    dec SI
    JMP moveBackSI  
    

 
swapMiddle:
   ; xor AL,AL
   ; xor DL,DL 
    
    mov SI, AX
    mov DI, DX
    
    ;mov AL, [SI]
    ;mov DL, [DI]
    
    JMP moveSIforMiddle
 
moveSIforMiddle:
    xor BL, BL
    mov BL, [SI]
    cmp BL, 32
    JNE incrementSIforMiddle
    inc SI
    JMP moveDIforMiddle
 
incrementSIforMiddle:  
    inc SI
    JMP moveSIforMiddle
 
moveDIforMiddle:
    xor BH, BH
    mov BH, [DI]
    cmp BH, 32
    JNE DecrementDIforMiddle
    dec DI
    JMP DecCX
 
DecrementDIforMiddle:
    dec DI
    JMP moveDIforMiddle
 
 
 
swap:
xor BL, BL
xor BH, BH 

mov BH, [SI] ;swap
mov BL, [DI]
mov [DI], BH
mov [SI], BL
inc SI
dec DI
JMP Compare
 
end start