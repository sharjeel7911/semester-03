;Sum of Odd Numbers in Array Using Stack
.model small
.stack 0x100
.data
     arr dw 0x10, 0x20, 0x3, 0x5, 0x11
     size dw 5 
     sum dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ax, offset arr
    push ax
    mov ax, size
    push ax
    mov ax, offset sum
    push ax
    call sumOdd
    add sp, 6
main endp
.exit     

;function definition
sumOdd proc
    push bp
    mov bp, sp
    
    mov si, [bp + 8] ; array offset
    mov cx, [bp + 6] ; size
    mov dx, [bp + 4] ; sum offset
    xor ax, ax
    
    sumLoop:
            cmp cx, 0
            je storeSum

            mov bx, [si]         
            test bx, 1           
            jz skip
            add ax, bx           
    skip:
         add si, 2           
         dec cx
         jmp sumLoop
    storeSum:
             mov bx, dx
             mov [bx], ax 
    pop bp            
    ret
sumOdd endp    