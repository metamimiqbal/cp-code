                          .model small
.stack 100h

.data
strinp db 'enter input: $'
strout db 'Entered Input: $'
newline db 0Ah, 0Dh, '$'
.code

main proc
     mov ax, @data
     mov ds, ax
     
     lea dx, strinp
     mov ah, 09h
     int 21h 
     
     call takeinp
     
     mov ah, 4ch
     int 21h 
main endp


takeinp proc
    xor cl, cl
    mov bl, 10
    inp:
        mov ah, 01h
        int 21h
        
        cmp al, 0Dh ; enter clicked
        je end
        
        xor ah, ah
        
        sub al, 30h
        mov dl, al
        mov al, cl
        mul bl
        add al, dl
        mov cl, al
        
        
        jmp inp
        
        
        
        
    end:    
    lea dx, strout
    mov ah, 09h
    int 21h
    
    ; print the entered digits:
    ;printPush:   
    
    lea dx, newline
    mov ah, 09h
    int 21h
    
    lea dx, strout
    mov ah, 09h
    int 21h
        
    xor ah, ah
    mov al, cl
    mov bl, 10
    xor cx, cx
    printPush: 
        xor ah, ah
        div bl
        push ax
        inc cx
        
    cmp al, 0
    jnz printPush
    
    
    popPushed:
        pop ax
        mov dl, ah
        add dl, 30h
        mov ah, 02h
        int 21h
        
    dec cx
    jnz popPushed
    
    
    ret
takeinp endp
end main