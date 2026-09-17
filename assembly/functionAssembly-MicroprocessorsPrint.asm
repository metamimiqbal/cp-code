.model small
.stack 100h
.data
msg db "The Output String is: ", '$'
newline db 0ah, 0dh, '$'
.code
MAIN proc
    mov AX, @DATA
    mov DS, AX

    lea dx, msg
    mov ah, 09h
    int 21h


    call lef       
    call md        
    call right 
    mov DL, 'S'
    INT 21H    
    
    lea dx, newline
    mov ah, 09h
    int 21h
    
    mov AH, 4CH
    INT 21H
MAIN ENDP


lef proc
    call lef_L1
    call lef_L2
    call lef_L3
    mov DL, 'R'      
    mov AH, 02H
    INT 21H
    RET
lef ENDP
md proc
    call md_L1
    mov DL, 'C'
    mov AH, 02H
    INT 21H
    RET
md ENDP
right proc
    call right_L1
    call right_L2
    mov DL, 'R'
    mov AH, 02H
    INT 21H
    RET
right ENDP

lef_L1 proc
    mov DL, 'M'
    mov AH, 02H
    INT 21H
    RET
lef_L1 ENDP

lef_L2 proc
    mov DL, 'I'
    mov AH, 02H
    INT 21H
    RET
lef_L2 ENDP

lef_L3 proc
    mov DL, 'C'
    mov AH, 02H
    INT 21H
    RET
lef_L3 ENDP

md_L1 proc  
    call md1_L1
    call md1_L2
    call md1_L3
    mov DL, 'O'
    mov AH, 02H
    INT 21H
    RET
md_L1 ENDP 

md1_L1 proc  
    mov DL, 'O'
    mov AH, 02H
    INT 21H
    RET
md1_L1 ENDP 
md1_L2 proc  
    mov DL, 'P'
    mov AH, 02H
    INT 21H
    RET
md1_L2 ENDP
md1_L3 proc  
    mov DL, 'R'
    mov AH, 02H
    INT 21H
    RET
md1_L3 ENDP

right_L1 proc
    mov DL, 'E'
    mov AH, 02H
    INT 21H
    RET
right_L1 ENDP

right_L2 proc 
    call right2_L1
    call right2_L2
    mov DL, 'O'
    mov AH, 02H
    INT 21H
    RET
right_L2 ENDP 

right2_L1 proc 
    mov DL, 'S'
    mov AH, 02H
    INT 21H
    RET
right2_L1 ENDP 
right2_L2 proc 
    mov DL, 'S'
    mov AH, 02H
    INT 21H
    RET
right2_L2 ENDP

END MAIN