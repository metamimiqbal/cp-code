.model small
.stack 100h
.data
vec db 45, 37, 11, 91, 4
print db 'SORTED ARRAY: $'
space db 20h, '$'
.code
mov ax, @data
mov ds, ax

mov si, 0
loop1:
    mov bx, 0
    loop2:
        mov al, vec[si]
        mov cl, vec[bx]
        cmp al, cl
        jge end
        mov vec[si], cl
        mov vec[bx], al
    end:
    inc bx
    cmp bx, 5
    jle loop2
inc si
cmp si, 5
jle loop1


lea dx, print
mov ah, 09h
int 21h

mov si, 0
traverse:
    mov al, vec[si]
    xor ah, ah
    mov bl, 10
    mov cx, 0
    pushVec:
        div bl
        push ax
        xor ah, ah
        inc cx
    cmp al, 0
    jnz pushVec

    popVec:
        pop ax
        mov dl, ah
        add dl, 30h
        mov ah, 02h
        int 21h
    dec cx
    cmp cx, 0
    jnz popVec 
    
    lea dx, space
    mov ah, 09h
    int 21h
inc si
cmp si, 5
jle traverse

