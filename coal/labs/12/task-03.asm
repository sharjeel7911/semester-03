;Write a program to clear the entire screen by filling it with spaces.
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0xb800
    mov es, ax
    
    mov di, 0
    mov cx, 2000
    printSpaces:
                mov al, ' '
                mov es:[di], al
                mov al, 0x07 ;white on black background
                mov es:[di + 1], al 
                add di, 2
    loop printSpaces       
;exit
mov ax, 0x4c00
int 0x21
main endp