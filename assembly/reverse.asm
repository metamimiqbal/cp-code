.model small
.stack 100h

.data
    msg1 db 0ah, 0dh, "Enter string: $"
    msg2 db 0ah, 0dh, "reverse string is: $"

.code
MAIN PROC
    mov ax, @data
    mov ds, ax

    mov ah, 09h
    lea dx, msg1
    int 21h


    takinginput:
        mov ah, 01h ; takes input in al
        int 21h            

        cmp al, 0dh        
        je reverse

        xor ah, ah ; resetting ah
        push ax         

        jmp takinginput

    reverse:
        mov ah, 09h
        lea dx, msg2
        int 21h

    printing:
        cmp sp, 100h
        je exit

        pop dx             

        mov ah, 02h ; output what's in dl
        int 21h

        jmp printing

    exit:
        mov ah, 4ch
        int 21h
MAIN ENDP
END MAIN