;AX = 1234h, BX = 5678h. Use the stack to swap their values (WITHOUT MOV AX, BX). Use only PUSH and POP.
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0x1234
    mov bx, 0x5678
    
    push ax
    push bx   
    
    pop ax
    pop bx
main endp
.exit 