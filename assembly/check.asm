.model small
.stack 100h
.data
arr2d db 1, 2, 3, 4
      db 5, 6, 7, 8
      db 19, 18, 17, 16
strnewline db 0Ah, 0Dh, '$'

.code
main proc
     mov ax, @data
     mov ds, ax
    
     mov ch, 0
     mov bx, 0
     ol:
        mov cl, 0
        mov si, 0
        il:
          mov al, arr2d[bx][si]
          xor ah, ah 
          
          call print
           
          mov dl, 20h
          mov ah, 02h
          int 21h
          
          add si, 1
          
        inc cl
        cmp cl, 4
        jl il 
        
        lea dx, strnewline
        mov ah, 09h
        int 21h
     add bx, 4
     inc ch
     cmp ch, 3
     jl ol   
     
     mov ah, 4ch
     int 21h
     
main endp     

print proc 
      push cx        
      mov bl, 10
      mov cx, 0
      pushing:
          div bl
          push ax
          xor ah, ah
          inc cx
       cmp al, 0
       jne pushing
       
       printing:
           pop ax
           mov dl, ah
           add dl, 30h
           mov ah, 02h
           int 21h
       dec cx
       jnz printing
       
       pop cx
       ret   
print endp

end main
