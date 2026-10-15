;find if n is prime
.model small
.stack 0x100
.data
     n dw 14     
.code
main proc
    mov ax, @data
    mov ds, ax       
    
    push n
    call isPrime
    add sp, 0x02     
;exit
mov ax, 0x4c00
int 0x21
main endp

;function definition
isPrime proc
    pop si
    pop bx
    push si
    xor si, si     
    cmp bx, 2
    jb notPrime ; numbers < 2 are not prime
    je primeNum ; 2 is prime
    
    mov cx, bx ;divider will always be <= to ax 
    shr cx, 1 ;divide by 2 {loop will run num / 2} 
    mov si, 2
    checkLoop:
              mov ax, bx
              xor dx, dx               
              div si
              cmp dx, 0
              je notPrime
              inc si
    loop checkLoop 

    primeNum:     
             xor ax, ax
             mov al, 1
             ret

    notPrime: 
             xor ax, ax
             mov al, 0
             ret
    ret          
isPrime endp