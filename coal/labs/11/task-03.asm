;Write a program that hooks 0x65 interrupt with the following services. The ISR should preserve all the registers except AX. 
;0x3 -> Divide the word pointed by SI by the byte pointed by DI and store quotient and remainder in the AL and AH registers, respectively. AL <- [SI]/[DI] and AH <- [SI] % [DI]  
.model small
.stack 0x100
.data 
     num1 dw 0x0255 ;can't go more than 255 cause it will overflow al and ah and remainder will store in dx. If there is no problem if remainder goes to dx then you can use value > 255  
     num2 db 0x07
.code
main proc
    mov ax, @data
    mov ds, ax
    mov ax, 0
    mov es, ax
    
    mov word ptr es:[0x65 * 4 + 0], isr3
    mov word ptr es:[0x65 * 4 + 2], cs
    
    lea si, num1
    lea di, num2
    
    mov ah, 0x03
    int 0x65 
;exit
mov ax, 0x4c00
int 0x21
main endp

;hooked service
isr3 proc
    push bx
    push cx
    push dx
    push si
    push di
    push ds
    push es
    
    cmp ah, 0x03
    jne exit
    
    mov ax, [si]    
    mov bl, [di]
    cmp bl, 0
    je exit     
    div bx
    
    exit:
         pop es
         pop ds
         pop di
         pop si
         pop dx
         pop cx
         pop bx
    iret
isr3 endp    