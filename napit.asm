.model  small
.stack  100h
.data
.code
MAIN
mov ax,  10h
mov bx,  10h-0Ah
mov cx,  ax
sub cx,  bx
add dx,  ax
add dx,  bx
add dx,  cx
mov cx, 0h
MAIN ENDP
END MAIN