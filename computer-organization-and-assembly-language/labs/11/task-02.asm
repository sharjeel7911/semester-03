;Write a program that hooks 0x65 interrupt with the following services. The ISR should preserve all the registers except AX. 
;0x2 -> Multiply two words pointed by SI and DI and store result in the memory pointed by BX. [BX] <- [SI] * [DI] 
.model small
.stack 0x100
.data 
     num1 dw 0x0005
     num2 dw 0x0020
     result dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
    mov ax, 0
    mov es, ax
    
    mov word ptr es:[0x65 * 4 + 0], isr2
    mov word ptr es:[0x65 * 4 + 2], cs
    
    lea si, num1
    lea di, num2
    lea bx, result
    
    mov ah, 0x02
    int 0x65 
;exit
mov ax, 0x4c00
int 0x21
main endp

;hooked service
isr2 proc
    push bx
    push cx
    push dx
    push si
    push di
    push ds
    push es
    
    cmp ah, 0x02
    jne exit
    
    mov ax, [si]
    mov cx, [di]
    mul cx
    mov [bx], ax 
    
    exit:
         pop es
         pop ds
         pop di
         pop si
         pop dx
         pop cx
         pop bx
    iret
isr2 endp    