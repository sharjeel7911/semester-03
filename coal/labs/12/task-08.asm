;Write a procedure named "print" that takes a null-terminated string as a parameter and displays it on the screen at the position of the cursor. The cursor increments accordingly whenever a string is displayed. (Hint: You need to keep cursor information in a global variable.)
.model small
.stack 0x100
.data 
     msg db 'Sharjeel Ahmad', 0
     len equ $-msg
     row dw 6
     col dw 51
.code
main proc
    mov ax, @data
    mov ds, ax
    push offset msg
    push len
    push row 
    push col
    call printString
    add sp, 8 
;exit
mov ax, 0x4c00
int 0x21                                
main endp

;function definition
printString proc
    mov ax, 0xb800
    mov es, ax
    
    push bp
    mov bp, sp
    mov ax, [bp + 6] ;row
    mov bx, [bp + 4] ;col 
    
    mov cx, 80 ;2 * (Row address * 80 + Column address)
    mul cx
    add ax, bx
    shl ax, 1
    mov di, ax
    
    mov cx, [bp + 8] ;length of string
    dec cx
    mov si, [bp + 10] ;offset string
    
    printLoop:
              mov al, [si]   
              mov es:[di], al
              mov al, 0x0f
              mov es:[di + 1], al
              inc si
              add di, 2
    loop printLoop
    pop bp 
    ret
printString endp        