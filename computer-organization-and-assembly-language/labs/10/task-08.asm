;Write a program that displays the character * five times on the screen. The character should appear in red color on the default video page.
.model small
.stack 0x100
.data
.code
main proc
    mov cx, 5                  
    mov al, '*'        
    mov bh, 0           
    mov bl, 0x0C        
      
    mov ah, 0x09
    int 0x10
;exit
mov ax, 0x4c00
int 0x21
main endp