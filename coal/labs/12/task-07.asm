;Write a program that prints numbers 0-9 in the first row using video memory
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0xb800
    mov es, ax 
    
    mov di, 0
    mov al, '0'  
    mov cx, 10 
    
    printLoop:
              mov es:[di], al 
              mov es:[di + 1], 0x07   
              add di, 2 
              inc al
              mov dl, ' '   
              mov es:[di], dl 
              mov es:[di + 1], 0x07 
              add di, 2 
    loop printLoop      
;exit
mov ax, 0x4c00
int 0x21
main endp