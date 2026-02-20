;Write a program that declares a byte array and stores an English word into it. The program then checks if the array contains a palindrome. It stores 1 in the DL register in the case of palindromes and 0 otherwise.  
.model small 
.stack 0x100
.data       
     arr db 'sharjeel', 0
     size dw 0x0008
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ax, offset arr
    push ax
    mov ax, size
    push ax
    call findPalindrome
    add sp, 0x4
main endp
.exit
 
;function definition
proc findPalindrome
    push bp
    mov bp, sp
    
    mov si, 0
    mov di, [bp + 4]
    dec di ;because array starts from 0 index
    mov bx, [bp + 6]
    
    twoPointer:
               cmp si, di
               jge isPalindrome
                   
               mov al, [bx + si]
               mov dl, [bx + di]
               cmp al, dl
               jne notPalindrome
               
               inc si
               dec di
    jmp twoPointer
    isPalindrome:
                 mov dl, 1
    jmp exit           
    
    notPalindrome:
                  mov dl, 0 
    exit:
    pop bp
    ret
findPalindrome endp     