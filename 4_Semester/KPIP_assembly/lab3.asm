.model small
.stack 100h

.data
buf db 30 dup ('$') 

message_enter db "Enter a array", 0Dh,0Ah,'$'
message_entered_array db 0Dh,0Ah,"Entered array:",0Dh,0Ah,'$'
message_wrong db 0Dh,0Ah,"Incorrect input",0Dh,0Ah,'$'
message_final_array db 0Dh, 0Ah, "Answer", 0Dh,0Ah,'$' 
message_overflow db 0Dh, 0Ah, "Overflow!", 0Dh, 0Ah, '$'
ARRAY dw 30 dup ('$')
ANSWER dw 2 dup ('$') 
eenter db 0Dh,0Ah,'$'

counter db 0 
counter_DI db 5


.code
start:
mov AX,@data
mov DS,AX

print_str macro out_str
    mov AH,9h
    mov DX,offset out_str
    int 21h
endm

print_str message_enter

xor CX,CX
xor DX,DX
mov CX,30 ;30 elements

enter_numbers:
    push CX
    push DX
    mov SI,offset buf
    mov CX,30
    mov BX,SI ;bx is at the beginning of the line

enter_string:
    mov AH,1h
    int 21h
    mov [SI],AL
    mov AH,0Dh
    cmp AL,AH
    JE part_1
    inc SI
loop enter_string


part_1:
        
        
    mov [SI],'$'
    print_str eenter

    mov SI,BX ;si at the beginning of the line
    xor BX,BX
    xor CX,CX
    xor DX,DX
    xor AX,AX
    xor DI,DI

    cmp BYTE PTR[SI],'-'
    JNE convert
    mov DI,1 ;if number is <0
    inc SI

convert:
    mov CX,10
    call convert_string_to_number

    cmp DI,1
    JNE part_2
    neg AX 
    JMP part_2

part_2:
    pop CX                              ; DX moves to CX
    mov SI,offset ARRAY
    mov DX,CX
    cmp CX,0
    JE write_number_into_array 
    
skip_occupied_positions:
    add SI, 2
loop skip_occupied_positions

write_number_into_array:
    inc DX                              ;position occupied
    mov [SI],AX
    pop CX
    loop enter_numbers  
    
    
;OUTPUT ARRAY

print_str message_entered_array

    xor DX,DX
    xor DI,DI
    xor CX,CX
    mov CX,30 

convert_number_to_string:
    push CX
    xor CX,CX
    mov SI,offset ARRAY
    mov CX,DI
    cmp CX,0
    JE output_part_2 
    
skip_occupied_positions_for_output:
   add SI, 2
loop skip_occupied_positions_for_output

output_part_2:
    inc DI
    xor AX,AX
    mov BX,10

    xor CX,CX
    call number_to_string_procedure
    pop CX
    loop convert_number_to_string

    xor DX,DX
    xor DI,DI

    xor CX,CX
    xor AX,AX
    mov SI,offset ARRAY
   ; mov DI,offset sum   
    
    ;MAIN PROGRAM
    
    mov SI, offset ARRAY    

    mov CX, 30
    xor AX, AX
    
    
    
    

arraySum:
   
   add AX, [SI]
   ;cmp AH,80h
   JO overflow
   add SI, 2
   loop arraySum 
   
average:
   test AX, AX
   JNS continue 
   neg AX
   mov DI, 1
continue:   
   mov BX, 30
   idiv BX
   
writeAnswerIntoVariable:
   mov SI, offset ANSWER
   cmp DI, 1
   JNE negContinue
   neg AX
negContinue:
   mov [SI], AX
   ;inc SI 
   ;mov [SI], '.'
   add SI, 2 
   xor AX, AX
   mov AX, DX
   mov BX, 1000
   mul BX
   mov BX, 30
   div BX
   mov [SI], AX 
   
  
end_of_sort:    
    ;END OF MAIN PROGRAM  
    
    
    print_str message_final_array

    xor DX,DX
    xor DI,DI
    xor CX,CX
    mov CX, 2 

convert_number_to_string_2:
    push CX
    cmp CX, 1
    JE separator
separatorBack:
    xor CX,CX
    mov SI,offset ANSWER
    mov CX,DI
    cmp CX,0
    JE output_part_2_2 
    
skip_occupied_positions_for_output_2:
   add SI, 2
loop skip_occupied_positions_for_output_2
    

output_part_2_2:
    inc DI
    xor AX,AX
    mov BX,10

    xor CX,CX
    call number_to_string_procedure
    pop CX
    loop convert_number_to_string_2

    xor DX,DX
    xor DI,DI

    xor CX,CX
    xor AX,AX
    JMP end_of_program
    
    ;END_OF_OUTPUT
    

wrong_input:
print_str message_wrong
JMP end_of_program

overflow:
print_str message_overflow
JMP end_of_program

convert_string_to_number proc near

again:
    mov BL,[SI]
    cmp BL,'$'
    JE exit_proc

    cmp BL, '.'
    JE  skip
    cmp BL,'0'
    JB wrong_input
    cmp BL,'9'
    JA wrong_input
    sub BL,'0'
    mul CX
    JO wrong_input ;check OF for overflow
    add AX,BX 
    cmp DI, 1
    JNE notNegative
    cmp AH, 80h
    JNE notNegative
    cmp AL, 00h
    JE number32768
    notNegative:
    cmp AH,80h ;check if number is >32767
    JAE wrong_input 
    number32768:
skip:
    inc SI
    jmp again

exit_proc: 
    ret
convert_string_to_number endp 



number_to_string_procedure proc 
    
    mov AX,[SI]
    test AX,AX
    JNS positive
    push AX
    mov AH,2h
    mov DL,'-'
    int 21h
    pop AX
    neg AX

positive:
    xor DX,DX
    div BX
    push DX 
    inc CX
    test AX,AX
    JNZ positive
    mov AH,2h

print_number:
    pop DX
    add DL,'0'   ;.....................
    int 21h

loop print_number

    mov AX,DI
    mov BL,30
    div BL
    cmp AH,0
    JNE space
    ;spaceSepatrator
    ret

space:
    mov AH,2h
    mov DL,' '
    int 21h 
ret  


number_to_string_procedure endp

separator:
    mov AH, 2h
    mov DL, '.'
    int 21h
    JMP separatorBack
    
spaceSeparator:
    mov AH, 2h
    mov DL, '.'
    int 21h
    

end_of_program:
    mov ax,4C00h
    int 21h
end start