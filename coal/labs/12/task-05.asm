;Write a program to display the string "HELLO" at row 12, column 30.
.model small
.stack 0x100
.data
     msg db 'HELLO' ;doesn't need '$' because we're manually handling the string
     len equ $-msg ;find length of string
.code
main proc
    mov ax, @data
    mov ds, ax
    mov ax, 0xb800
    mov es, ax 
    
    mov di, 0x07bc  ;(12 * 80 + 30) * 2  
    
    mov cx, len 
    mov si, 0
    printString:
                mov al, msg[si]      
                mov es:[di], al
                mov al, 0x07 ;white on black background
                mov es:[di + 1], al 
                add di, 2  
                inc si
    loop printString
    hlt       
;exit
mov ax, 0x4c00
int 0x21
main endp