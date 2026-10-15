;Write a program that takes one character input from the user without displaying it on the screen. After input, print a message saying that the character was successfully received.
.model small
.stack 0x100
.data
     msg db 'A single digit input received.$'
     ;msg db 'A single digit input received.', 0 ->it won't work
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ah, 0x07 ;without echo, it takes a single digit input from keyboard
    int 0x21
    
    mov dx, offset msg 
    mov ah, 0x09 ;outputs string in ds:dx on console
    int 0x21
;exit
mov ax, 0x4c00
int 0x21
main endp   