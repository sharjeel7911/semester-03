;Write a program that displays the message "WELCOME TO ASSEMBLY". Make sure the string is properly terminated and stored in the data segment.
.model small
.stack 0x100
.data
     msg db 'WELCOME TO ASSEMBLY$' 
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov dx, offset msg 
    mov ah, 0x09 ;outputs string from dx using offset
    int 0x21
;exit
mov ax, 0x4c00
int 0x21
main endp