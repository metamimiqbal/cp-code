.model small
.stack 100h
.data
arr db 5, 61, 31, 21, 10, 8, 16
        
newline db 0dh, 0ah, '$'
space db 20h, '$'
.code
MAIN proc
    mov AX, @DATA
    mov DS, AX 
    
    ; sorting
    
    mov si, 0
    loop1:
         mov bx, 0
         
         loop2:    
             
             mov al, arr[bx]
             mov cl, arr[bx+1]
             
             cmp al, cl
             jl end
             mov arr[bx], cl
             mov arr[bx+1], al
         
         end:
         inc bx
         cmp bx, 6
         jl loop2 
    
    inc si
    cmp si, 6
    jl loop1
      
    
    mov si, 0
    traverse:
            mov al, arr[si]  
            xor ah, ah
            mov bl, 10
            mov cx, 0
            printPush:
                div bl ; al - quotient, ah - remainder
                push ax
                xor ah, ah
                inc cx 
            cmp al, 0
            jnz printPush                
            
            
            print: 
                pop ax
                mov dl, AH
                ADD dl, 30h
                mov ah, 02h
                int 21H

                ;mov ah, 02h 
                ;pop bx  
                ;mov dx, bx
                ;xchg dh, dl
                ;add dl, 30h
                ;int 21h 
                 
                dec cx
                jnz print
                
    lea dx, space
    mov ah, 09h
    int 21h      
          
    inc si
    cmp si, 7
    jl traverse
    
       
    mov AH, 4CH
    INT 21H
MAIN ENDP
END MAIN