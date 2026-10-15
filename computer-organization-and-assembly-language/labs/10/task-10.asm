;Write a program that inputs two 16-bit hexadecimal numbers from the user and displays their sum on the screen. 
.model small
.stack 0x100
.data
     msg1 db "Enter first hex number (4 digits): $"
     msg2 db "Enter second hex number (4 digits): $"
     msg3 db 0x0d, 0x0a, "Sum: $"
     newline db 0x0d, 0x0a, "$"
     num1 dw 0
     num2 dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov dx, offset msg1
    mov ah, 0x09
    int 0x21
    
    call inputHex
    mov num1, bx       
    
    mov dx, offset newline
    mov ah, 0x09
    int 0x21
    
    mov dx, offset msg2
    mov ah, 0x09
    int 0x21
    
    call inputHex
    mov num2, bx        
                    
    mov ax, num1
    add ax, num2         
    mov bx, ax          
                           
    mov dx, offset msg3
    mov ah, 0x09
    int 0x21
                  
    call printHex
                    
    mov dx, offset newline
    mov ah, 0x09
    int 0x21
;exit
mov ax, 0x4c00
int 0x21
main endp

;procedure to input a 4-digit hex number
inputHex proc
    push ax
    push cx
    push dx
    
    mov bx, 0           ; Initialize result
    mov cx, 4           ; 4 hex digits
    
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
              sub al, 0x20 ;if reaches here means user entered a lowercase letter
              
              letter:
                     sub al, 'A' - 10 ;A = 0x41
                     jmp combine

              digit:
                    sub al, '0' ;0 = 0x30

              combine:
                      shl bx, 4 ; multiply current value by 16
                      add bl, al  
    loop inputLoop
    pop dx
    pop cx
    pop ax
    ret
inputHex endp

;procedure to print a 16-bit hex number
printHex proc
    push ax
    push bx
    push cx
    push dx
    
    mov cx, 4           
    
    printLoop:
              rol bx, 4          ;bring next hex digit to low nibble 
              mov al, bl
              and al, 0x0f         ;isolate 1 hex digit (0 – 15)

              cmp al, 9
              jbe digits

              add al, 7           ;adjust for A – F

              digits:
                    add al, '0'         ;convert to ASCII
              mov dl, al
              mov ah, 0x02
              int 0x21  
    loop printLoop
    pop dx
    pop cx
    pop bx
    pop ax
    ret
printHex endp