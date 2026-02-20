;Write a code that prints a number stored in a 16-bit variable on screen in a hexadecimal radix.
.model small
.stack 0x100
.data
     msg db "Hex value: $"
     num dw 0x1f3A
.code
main proc
    mov ax, @data
    mov ds, ax
               
        mov dx, offset msg
        mov ah, 09h
        int 21h 
        
        mov bx, num          
        mov cx, 4  
        
        printLoop:
                   rol bx, 4 ;bring next hex digit to low nibble 
                   mov al, bl
                   and al, 0x0f ;isolate 1 hex digit (0 – 15)
    
                   cmp al, 9
                   jbe digit
                   
                   ;9 = 39(ascii) -> 4a, 4b, 4c, 4d, 4e, 4f, 40, [41(A ascii)] {for digit, we add 0x30, for letter we will add (0x30 + 0x07)}
                   add al, 0x7 ;adjust for A – F [f = 0xf + 0x7 = 0x16 -> then 0x16 + 0x30 = 0x46[F ascii] after digit label runs]
    
                   digit:
                         ;add al, 0x30
                         add al, '0' ;convert to ascii
                   mov dl, al
                   mov ah, 0x02
                   int 0x21  
        loop printLoop               
;exit
mov ax, 0x4c00
int 0x21
main endp