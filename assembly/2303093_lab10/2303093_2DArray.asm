.model small 
.stack 100h

.data
marks db 12 dup(?)

msg_in1  db 'Enter marks of student $'
msg_in2  db ' (A B C): $'
msg_sum1 db 'Sum of student $'
msg_eq   db ' = $'
msg_arr  db 'Marks table:', 0Dh, 0Ah
         db '  ', 9, 'A', 9, 'B', 9, 'C', 0Dh, 0Ah, '$'
    
.code
main proc
     mov ax, @data
     mov ds, ax
     
     mov ch, 0
     mov bx, 0
     
     in_ol:
         mov dx, offset msg_in1
         mov ah, 09h
         int 21h
         
         mov dl, ch
         add dl, 31h
         mov ah, 02h
         int 21h
         
         mov dx, offset msg_in2
         mov ah, 09h
         int 21h
         
         mov cl, 0
         mov si, 0
         in_il:
            call read_num
            mov marks[bx][si], al
            
            add si, 1
            
            inc cl
            cmp cl, 3
            jl in_il
            
        add bx, 3
        inc ch
        cmp ch, 4
        jl in_ol
     
     
     call newline
     
     mov ch, 0
     mov bx, 0
     
     sum_ol:
         mov cl, 0
         mov si, 0
         mov di, 0
         sum_il:
            mov al, marks[bx][si]
            mov ah, 0
            add di, ax
            
            add si, 1
            
            inc cl
            cmp cl, 3
            jl sum_il
         
         mov dx, offset msg_sum1
         mov ah, 09h
         int 21h
         
         mov dl, ch
         add dl, 31h
         mov ah, 02h
         int 21h
         
         mov dx, offset msg_eq
         mov ah, 09h
         int 21h
         
         mov ax, di
         call print_num
         call newline
        
        add bx, 3
        inc ch
        cmp ch, 4
        jl sum_ol
     
     
     call newline
     mov dx, offset msg_arr
     mov ah, 09h
     int 21h
     
     mov ch, 0
     mov bx, 0
     
     pr_ol:
         mov dl, ch
         add dl, 31h
         mov ah, 02h
         int 21h
         
         mov dl, ':'
         mov ah, 02h
         int 21h
         
         mov cl, 0
         mov si, 0
         pr_il:
            mov dl, 9
            mov ah, 02h
            int 21h
            
            mov al, marks[bx][si]
            mov ah, 0
            call print_num
            
            add si, 1
            
            inc cl
            cmp cl, 3
            jl pr_il
         
         call newline
         
        add bx, 3
        inc ch
        cmp ch, 4
        jl pr_ol
     
     mov ah, 4ch
     int 21h
main endp


read_num proc
     push bx
     push cx
     push dx
     
     mov bx, 0
     
     rn_loop:
        mov ah, 01h
        int 21h
        
        cmp al, '0'
        jl rn_done
        cmp al, '9'
        jg rn_done
        
        sub al, 30h
        mov ah, 0
        mov cx, ax
        mov ax, bx
        mov dx, 10
        mul dx
        add ax, cx
        mov bx, ax
        jmp rn_loop
     
     rn_done:
        cmp al, 0Dh
        jne rn_end
        mov dl, 0Ah
        mov ah, 02h
        int 21h
     
     rn_end:
        mov ax, bx
        
     pop dx
     pop cx
     pop bx
     ret
read_num endp


print_num proc
     push ax
     push bx
     push cx
     push dx
     
     mov bx, 10
     mov cx, 0
     pn_div:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        jne pn_div
     
     pn_out:
        pop dx
        add dl, 30h
        mov ah, 02h
        int 21h
        loop pn_out
     
     pop dx
     pop cx
     pop bx
     pop ax
     ret
print_num endp


newline proc
     push ax
     push dx
     mov dl, 0Dh
     mov ah, 02h
     int 21h
     mov dl, 0Ah
     mov ah, 02h
     int 21h
     pop dx
     pop ax
     ret
newline endp

end main