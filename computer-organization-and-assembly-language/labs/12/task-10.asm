;Incorporate the functionality of scroll up to the print procedure you created in task 1. 
.model small
.stack 0x100
.data 
     msg db 'Sharjeel Ahmad', 0
     len equ $-msg
     row dw 24
     col dw 78
.code
main proc
    mov ax, @data
    mov ds, ax
    mov cx, len
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
              cmp di, 4000
              jl noScroll
              call scrollUpward
              sub di, 160    
              noScroll:
                       mov al, [si]
                       mov es:[di], al
                       mov al, 0x0a
                       mov es:[di + 1], al
                       inc si
                       add di, 2    
    loop printLoop    
    pop bp 
    ret
printString endp        

;function definition
scrollUpward proc 
    push si  
    push di
    push cx
    push ax     
    push es

    
    mov ax, 0xb800
    mov es, ax 
    
    mov si, 160 ;2 * 80
    mov di, 0
    mov cx, 1920 ;80 * 24    
    
    scrollLoop:
               mov ax, es:[si]        
               mov es:[di], ax
               add si, 2
               add di, 2
    loop scrollLoop
    
    mov di, 3840
    mov cx, 80
    clearWithSpace:            
                   mov es:[di], ' '
                   add di, 2
    loop clearWithSpace
    exitScroll:
               pop es
               pop ax
               pop cx
               pop di
               pop si           
    ret
scrollUpward endp