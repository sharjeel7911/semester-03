;Develop an assembly language program that accepts two two-digit number from the user and adds them. -> 12 + 12 = 24
.model small
.stack 0x100
.data
     msg1 db 'Enter first number: $'
     msg2 db 'Enter second number: $' 
     msg3 db 'SUM: $'
     num1 db ?
     num2 db ?
     sum  db ?
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov dx, offset msg1 ;show message
    mov ah, 0x09
    int 0x21 
    
    mov ah, 0x01 ;first digit
    int 0x21
    sub al, '0'
    mov bl, al
    mov al, 10
    mul bl ;bl * 10
    mov bl, al
    
    mov ah, 0x01 ;second digit
    int 0x21
    sub al, '0'
    add bl, al ;complete two-digit number
    mov num1, bl

    mov ah, 02 ;set cursor position
    mov dh, 1
    mov dl, 80
    mov bh, 0
    int 0x10 
    
    mov dx, offset msg2 ;show message
    mov ah, 0x09
    int 0x21
    
    mov ah, 0x01 ;1st digit
    int 0x21
    sub al, '0'
    mov bh, al
    mov al, 10
    mul bh
    mov bh, al
 
    mov ah, 0x01 ;2nd digit
    int 0x21
    sub al, '0'
    add bh, al
    mov num2, bh

    ;Sum
    mov al, num1
    add al, num2
    mov sum, al

    mov ah, 02 ;set cursor position
    mov dh, 3
    mov dl, 160
    mov bh, 0
    int 0x10 
    
    mov dx, offset msg3 ;show message
    mov ah, 0x09
    int 0x21
    
    mov al, sum
    mov ah, 0
    mov bl, 10
    div bl ;al = tens, ah = ones

    add al, '0'
    mov dl, al
    mov ah, 0x02
    int 0x21

    add ah, '0'
    mov dl, ah
    mov ah, 0x02
    int 0x21
;exit    
mov ax, 0x4c00
int 0x21
main endp    