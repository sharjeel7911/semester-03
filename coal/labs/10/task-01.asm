;Write an assembly language program that reads a single character from the keyboard. The program should display the same character automatically on the screen and then terminate.
.model small
.stack 0x100
.data
.code
main proc
    mov ah, 0x01 ;with echo, it takes a single digit input from console
    int 0x21
;exit
mov ax, 0x4c00
int 0x21
main endp   