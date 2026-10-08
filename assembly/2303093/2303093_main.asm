.model small
.stack 100h
.data


price db 30, 12, 10, '$'
stock db 8, 6, 9, '$'

typ db "Enter type: $"
none db 'INSUFFICIENT STOCK Print: $'
spc db 20h, '$'
nl db 0Dh, 0Ah, '$'  
payable db 'Total Payable: $'
discount_print db 'Discount : $'
.code
main proc
     mov ax, @data
     mov ds, ax
     mov es, ax
     
     lea dx, typ
     mov ah, 09h
     int 21h 
     
     
     mov ah, 01h
     int 21h
     mov dl, al ; type <- input
     
     
     push dx;saving dl
     lea dx, nl
     mov ah, 09h
     int 21h
     xor si, si
     mov dx, 0
     lp:
       mov ah, 01h
       int 21h
       cmp al, 0Dh
       je lp
       sub al, 30h
       ; al - user quantity input
       mov cl, stock[si]
       cmp cl, al
       jb nothing
       mov bl, price[si]
       sub cl, al
       mov stock[si], cl
       mul bl ; price * stock (al): user input = ax
       add dx, ax ; total expense
 
       jmp ok
       nothing:
       push dx
       lea dx,none
       mov ah, 09h
       int 21h 
       pop dx
     ok:
     inc si
     cmp si, 3
     jl lp
     
     mov ax, dx ; expense
     pop dx; now dl is the type
     cmp dl, 'S'
     je discount
     
     push ax
     jmp done
     discount: ; 10%
     mov dx, ax
     mov bl, 10
     div bl ; al: discount
     xor ah, ah
     
     sub dx, ax ;expense after discount
     push dx ; saving after discount expense
     push ax ; saving: discount
     
     lea dx, nl
     mov ah, 09h
     int 21h
     
     lea dx, discount_print
     mov ah, 09h
     int 21h
     pop ax ; unlocking: discount
     
     ; printing 
      mov bl, 10
      xor cx, cx
      pushing:
          div bl
          push ax
          xor ah, ah
          inc cx
      cmp al, 0
      jnz pushing
      
      poping:
          pop ax
          mov dl, ah
          add dl, 30h
          mov ah, 02h
          int 21h
      dec cx
      jnz poping  
      
      
    
     done:
     ; printing: payable  
     lea dx, nl
     mov ah, 09h
     int 21h
     lea dx, payable
     mov ah, 09h
     int 21h
     pop dx ; unlocking: expense 
     mov ax, dx
     
      mov bl, 10
      xor cx, cx
      pushing2:
          div bl                   
          push ax
          xor ah, ah
          inc cx
      cmp al, 0
      jnz pushing2
      
      poping2:
          pop ax
          mov dl, ah
          add dl, 30h
          mov ah, 02h
          int 21h
      dec cx
      jnz poping2    
     
     
     mov ah, 4ch
     int 21h
main endp
end main 


