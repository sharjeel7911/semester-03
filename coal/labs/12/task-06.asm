;Write an assembly routine that fills the screen with white characters on a blue background.
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0xb800
    mov es, ax 
    
    mov di, 0  
    mov cx, 2000  
    
    printString:
                mov al, '*'
                mov es:[di], al       
                mov al, 0x1f
                mov es:[di + 1], al   
                add di, 2
    loop printString      
;exit
mov ax, 0x4c00
int 0x21
main endp