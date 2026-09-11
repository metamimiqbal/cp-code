                    .model small
.stack 100h
.data
arr db 5, 61, 31, 21, 10, 8, 16
        
newline db 0ah, 0dh, '$'
.code
MAIN proc
    mov AX, @DATA
    mov DS, AX 
    
    ; find max, min, average
    ; sort the array
    ; traverse array 
    
    ; bx, bp, si, di allowed to load address
            
    mov si, 0
    mov cl, arr[si] 
    
    ; average
    
    mov cl, 0
    lp:
        add cl, arr[si]
              
       
    inc si
    cmp si, 7
    jl lp    
    
    mov bx, 7 
    xor ch, ch
    mov ax, cx
    div bx ; al = sum/7
    
    xor ah, ah
    
    mov bx, 10 
    mov cx, 0
    printPush:
        div bx ; al - quotient, ah - remainder
        push ax
        xor ah, ah 
        inc cx
        cmp al, 0
        jnz printPush
        
    mov ah, 02h
    print:
        pop bx  
        
        mov dx, bx
        xchg dh, dl
        add dl, 30h
        int 21h
        
    dec cx 
    cmp cx, 1
    jne print
       
    mov AH, 4CH
    INT 21H
MAIN ENDP
END MAIN