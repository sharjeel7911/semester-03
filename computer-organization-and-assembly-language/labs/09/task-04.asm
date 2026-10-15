;Access the 3rd Value from Stack Without Using POP
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0x5
    push ax
    mov ax, 0x10
    push ax
    mov ax, 0x20
    push ax
    
    mov ax, 0
    push bp
    mov bp, sp
    mov ax, [bp + 6]
    pop bp
    add sp, 6
main endp
.exit    