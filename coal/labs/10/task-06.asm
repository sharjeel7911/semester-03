;Write a code that inputs a 16-bit integer number in hexadecimal radix from the keyboard and store it in a variable.
.model small
.stack 0x100
.data
     msg db "Enter 16-bit hexadecimal number: $"
     num dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
               
    mov dx, offset msg
    mov ah, 0x09
    int 0x21
    xor bx, bx          
    mov cx, 4  
    
    inputLoop:
              mov ah, 0x01
              int 0x21
                         
              cmp al, '0' ;checks if lower than 0 
              jb inputLoop
              cmp al, '9' ;checks if between 0 - 9
              jbe digit
              cmp al, 'A' ;checks if between 9 and A (there are other ascii values between)
              jb inputLoop
              cmp al, 'F' ;checks if between A - F
              jbe letter
              cmp al, 'a' ;checks if between F and a  
              jb inputLoop
              cmp al, 'f' ;checks if greater than f
              ja inputLoop
              
              ;sub al, 0x57 [if you want to just convert it to hex directly. But then you have to jump to combine.]
              sub al, 0x20 ;if reaches here means user entered a lowercase letter
              
              letter:
                     ;sub al, 0x37
                     sub al, 'A' - 0xa ;A = 0x41 [0x41 - 0xa = 0x37]
                     jmp combine

              digit:
                    ;sub al, 0x30
                    sub al, '0' ;0 = 0x30

              combine:
                      shl bx, 4 ; multiply current value by 16
                      add bl, al  
    loop inputLoop
    mov num, bx                
;exit
mov ax, 0x4c00
int 0x21
main endp