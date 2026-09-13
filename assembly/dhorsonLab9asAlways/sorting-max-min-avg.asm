.model small
.stack 100h
.data
arr db 5, 61, 31, 21, 10, 8, 16
printMax db 'Maximum print: $'
printMin db 'Minimum print: $'
printAvg db 'Average pring [floor value]: $'
printSortedArray db 'Sorted Array: $'        
newline db 0dh, 0ah, '$'
space db 20h, '$'
.code
MAIN proc
    mov AX, @DATA
    mov DS, AX 
    
    ; maximum
    mov si, 0
    mov cl, arr[si]
    traversing:
        cmp arr[si], cl
        jle end
        mov cl, arr[si]
    
    end:
    inc si
    cmp si, 7
    jl traversing
    
    lea dx, printMax
    mov ah, 09h 
    int 21h
    
    
    xor ch, ch
    mov ax, cx
    mov bl, 10
    xor cx, cx
    printDiv:
        div bl
        push ax
        xor ah, ah
        inc cx
        
    cmp al, 0
    jnz printDiv
    
    popDiv:
       pop ax
       ;xchg al, ah
       mov dl, ah
       add dl, 30h
       mov ah, 02h
       int 21h
       
    dec cx
    cmp cx, 0
    jnz popDiv   
    
    
    
     ; minimum
    mov si, 0
    mov cl, arr[si]
    mintraversing:
        cmp arr[si], cl
        jge minend
        mov cl, arr[si]
    
    minend:
    inc si
    cmp si, 7
    jl mintraversing
     
    lea dx, newline
    mov ah, 09h 
    int 21h 
     
    lea dx, printMin
    mov ah, 09h 
    int 21h 
    
    
    xor ch, ch
    mov ax, cx
    mov bl, 10
    xor cx, cx
    minprintDiv:
        div bl
        push ax
        xor ah, ah
        inc cx
        
    cmp al, 0
    jnz minprintDiv
    
    minPopDiv:
       pop ax
       mov dl, ah
       add dl, 30h
       mov ah, 02h
       int 21h
       
    dec cx
    cmp cx, 0
    jnz minPopDiv
     
     
    ; average
    mov si, 0
    mov al, 0
    avgTraverse:
         add al, arr[si]
    
    inc si
    cmp si, 7
    jl avgTraverse      
    
    xor ah, ah
    mov bl, 7 
    div bl
    mov cl, al
    
    lea dx, newline
    mov ah, 09h
    int 21h
    
    lea dx, printAvg
    mov ah, 09h
    int 21h     
    
    mov bl, 10  
    xor ah, ah
    mov al, cl  
    xor cx, cx
    pushAvg:  
        div bl
        push ax
        xor ah, ah
        inc cx
        
    cmp al, 0
    jnz pushAvg
    
    
    popAvg:
         pop ax
         mov dl, ah
         add dl, 30h
         mov ah, 02h
         int 21h
    
    dec cx
    cmp cx, 0
    jnz popAvg
    
    
    ; sorting
    
    mov si, 0
    loop1:
         mov bx, 0
         
         loop2:    
             
             mov al, arr[bx]
             mov cl, arr[bx+1]
             
             cmp al, cl
             jl endMax
             mov arr[bx], cl
             mov arr[bx+1], al
         
         endMax:
         inc bx
         cmp bx, 6
         jl loop2 
    
    inc si
    cmp si, 6
    jl loop1
     
    lea dx, newline  
    mov ah, 09h
    int 21h   
    
    lea dx, printSortedArray
    mov ah, 09h
    int 21h
    
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