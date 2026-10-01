.model small
.stack 100h

.data
str1 db "Hello ",'W',6Fh,"rld",0ah,0dh,'$'
str2 db "llo$"


.code
main proc
     mov ax, @data
     mov ds, ax
     mov es, ax

     lea di, str1
     lea si, str2

     mov cx, 9          
     
     lp1:
       push cx

       lea si, str2
       mov cx, 3        

       repe cmpsb      

       jz found

       pop cx
       lea si, str2
       sub di, 2

       loop lp1
       jmp end      

     found:
       pop cx
       mov dl, 46h     
       mov ah, 2
       int 21h

     end:
       mov ah, 09h
       lea dx, str2
       int 21h

       mov ah, 4ch
       int 21h

main endp
end main