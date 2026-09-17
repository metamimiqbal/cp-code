.model small 
.stack 100h

.data
;strnewline db 0Ah, 0Dh, '$'
    
    
.code
main proc
     mov cx, 4
     printingStar:
          call printStar
     loop printingStar  
     
     call lineStar
     
     
     mov ah, 4ch
     int 21h
main endp

newline proc
      mov ah, 02h
      mov dl, 0ah
      int 21h
      mov ah, 02h
      mov dl, 0Dh
      int 21h
      
      ret
newline endp


printStar proc
    mov ah, 02h
    mov dl, '*' 
    int 21h
    
    mov bx, 3
    space:
        mov dl, 20h
        int 21h
        
    dec bx
    jnz space
    
    mov dl, '*' 
    int 21h 
    
    call newline
           
    ret
printStar endp

lineStar proc
    mov cx, 5
    starring:
        mov ah, 02h
        mov dl, '*'  
        int 21h
     loop starring
     
     ret
lineStar endp


end main