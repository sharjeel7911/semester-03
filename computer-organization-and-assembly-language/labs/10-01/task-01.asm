;Sum of squares upto nth number
.model small
.stack 0x100
.data
     n dw 0x05      
.code
main proc
    mov ax, @data
    mov ds, ax

    mov ax, n
    push ax
    call sumSquares
    add sp, 0x02
;exit
mov ax, 0x4c00
int 0x21    
main endp

;function definition
sumSquares proc
    push bp
    mov bp, sp
     
    mov si, 0x1  
    xor cx, cx

    SumLoop:
            mov dx, [bp + 0x04] 
            cmp si, dx
            ja done 
            
            mov bx, si 
            mov ax, bx
            mul bx
            add cx, ax
            
            inc si
    jmp SumLoop
    done:     
         mov ax, cx
    pop bp
    ret
sumSquares endp