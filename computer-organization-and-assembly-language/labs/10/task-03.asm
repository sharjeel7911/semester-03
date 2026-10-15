;Write a program that prints a single character # on the screen. The character must be passed through the correct register before calling the interrupt.
.model small
.stack 0x100
.data
     num db '#' 
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov dl, num
    mov ah, 0x02 ;outputs a character in dl to console
    int 0x21
;exit
mov ax, 0x4c00
int 0x21
main endp   