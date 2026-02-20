.model small
.stack 0x100
.data
     msg db 'Hey, I am Sharjeel Ahmad currently pursuing BsCs at University of Central Punjab, Lahore. This is assignment - 03 of COAL...!$'
     row dw 0
     col dw 0
.code
main proc  
    mov ax, @data
    mov ds, ax
    
    mov ax, offset msg
    push ax
    mov ax, row
    push ax
    mov ax, col
    push ax
   
    call printString
    add sp, 6  
mov ax, 0x4c00
int 0x21
main endp

;function definition
printString proc
    push bp
    mov bp, sp
    
    push ax
    push bx
    push cx
    push dx
    push si
    push di

    mov si, [bp + 4] ;offset string
    mov ax, [bp + 6] ;row
    mov bl, 80
    mul bl ;ax = row * 80
    add ax, [bp + 8] ;ax = row * 80 + col
    shl ax, 1 ;ax = (row * 80 + col) * 2
    mov di, ax ; di = video memory offset
    
    mov ax, 0xb800 ;video memory segment
    mov es, ax

    printLoop:
              mov al, [si]            
              cmp al, '$'
              je exit           
              
              mov es:[di + 0], al
              mov byte ptr es:[di + 1], 0x07      ;grey character with black background
              add si, 01
              add di, 02              
              
              cmp di, 4000          
              jb printLoop   
              
              call scrollUpward           
              mov di, 3840
    jmp printLoop          
    exit:
         pop di
         pop si
         pop dx
         pop cx
         pop bx
         pop ax
         pop bp
    ret
printString endp 

;function definition
scrollUpward proc 
    push si  
    push di
    push cx
    push ax
    
    mov ax, 0xb800
    mov es, ax 
    
    mov si, 160             ;2 * 80
    mov di, 0
    mov cx, 1920            ;80 * 24    
    
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
               pop ax
               pop cx
               pop di
               pop si           
    ret
scrollUpward endp