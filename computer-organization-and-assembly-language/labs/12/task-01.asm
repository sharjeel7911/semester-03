;Write an assembly program to display the character 'A' at the top-left corner of the screen using direct video memory access.
.model small
.stack 0x100
.data
.code
main proc
    mov ax, 0xb800
    mov es, ax
    
    mov di, 0
    mov al, 'A'
    mov es:[di], al 
    inc di
    mov al, 0x0f
    mov es:[di], al    
;exit
mov ax, 0x4c00
int 0x21
main endp    