;Write a program that asks the user to enter a password(no echo). If the entered password matches a predefined value, display "ACCESS GRANTED" on the screen. Otherwise, terminate the program.
.model small
.stack 0x100
.data
     pass db 'rhtje$'
     validate db 50 dup(?)
     passLen db 0x0005
     str db 'Enter Password: $'
     msg db 'Access Granted$'
     msgX db 'Access Denied$'
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, str
    mov ah, 0x09
    int 0x21
    
    xor bx, bx
    takeInput:
              ;take one char input from user                        
              mov ah, 0x07
              int 0x21 
              
              cmp al, 0x0d ;check ENTER key
              je inputCompleted
              mov [validate + bx], al 
              
              ;print * for each char of password
              mov dl, '*'
              mov ah, 0x02
              int 0x21
              
              inc bx
              cmp bx, 50
    jb takeInput
   
    inputCompleted:     
                   mov si, 0
    checkLoop:
              cmp si, bx
              je checkLen 
              mov al, [validate + si] 
              cmp al, [pass + si]
              jne failedAttempt
              inc si
    jmp checkLoop
    
    checkLen:
             mov al, bl
             cmp al, passLen
             jne failedAttempt 
             
             ;set cursor on next line
             mov dh, 1
             mov dl, 0
             mov bh, 0x00
             mov ah, 0x02
             int 0x10
              
             mov dx, offset msg
             mov ah, 0x09
             int 0x21
             jmp exit
    failedAttempt:
                  ;set cursor on next line with (newline + carrige return)
                  mov dl, 0x0a
                  mov ah, 0x02
                  int 0x21
                  mov dl, 0x0d
                  mov ah, 0x02
                  int 0x21
                   
                  mov dx, offset msgX
                  mov ah, 09h
                  int 21h 
    exit:      
;exit
mov ax, 0x4c00
int 0x21
main endp