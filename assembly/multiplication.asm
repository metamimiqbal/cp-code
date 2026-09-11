.model small
.stack 100h
.data        
input1 db "Number-1 input: $"
input2inp db "Number-2 input: $"
newline db 0ah, 0dh, '$'
.code
MAIN proc
    mov AX, @DATA
    mov DS, AX
    lea dx, input1
    mov ah, 09h
    int 21h
    ; taking input a 
    mov bl, 0
    input:
        mov ah, 01h
        int 21h ; input in al
        cmp al, 0dh
        je input1end
        sub al, 30h
        
        add bl, al; bl = a 
    
    jmp input
    
    input1end:
    
    lea dx, newline
    mov ah, 09h  
    int 21h
    lea dx, input2inp
    mov ah, 09h
    int 21h
    
    input2:
        mov ah, 01h
        int 21h ; input in al
        cmp al, 0dh
        je end
        sub al, 30h
        add bl, al ; bl = a+b 
    
    jmp input2
    
    end:        
    
    lea dx, newline
    mov ah, 09h
    int 21h
    
    
    mov al, bl
    mul bl ; bl = (al*bl) = (al*al) = (a+b)^2  -> ax = (a+b)^2
    
    
    ; print ax in full decimal form
    
    mov cx, 0
    print:
        mov bl, 10
        div bl ; dividing ax/bl 
        ; to push ah 
        push ax
        xor ah,ah
        inc cx
        cmp al, 0
        je printing
                 
     jmp print   
     
     printing: 
        pop bx
        mov dx, bx 
        xchg dl, dh
        add dl, 30h
        mov ah, 02h
        int 21h
     loop printing
       
    mov AH, 4CH
    INT 21H
MAIN ENDP
END MAIN