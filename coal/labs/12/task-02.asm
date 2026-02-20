;Write instructions to print the character 'X' in red color on black background at row 10, column 20.
.model small
.stack 0x100
.data
.code
main proc     
    mov ax, 0xb800
    mov es, ax
    
    mov di, 0x0668; (10 * 80 + 20)* 2

    mov al, 'X'
    mov es:[di], al
    inc di
    mov al, 0x04
    mov es:[di], al
;exit
mov ax, 0x4c00
int 0x21
main endp 