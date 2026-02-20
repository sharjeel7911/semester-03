.model small 
.stack 0x100
.data       
     arr db 1,2,3,5
.code
main proc
    mov ax, @data 
    mov ds, ax
    
    mov bx, offset arr
    
    mov si, 0
    
    mov ah, 0
    mov al, arr[si]
    mov dl, arr[si + 1]
    
    add al, dl
    
    mov dl, arr[si + 2] 
    sub al, dl
    
    mov dl, arr[si + 3] 
    add al, dl
    
    mov dx, ax 
    
    rcr ax, 1
    jnc evenNum
    
    mov ax, 0x1357 
    mov ds, ax
    mov bx, 0xa
            
    mov  [bx], dx 
    jmp skip 
    
    evenNum:
            mov ax, 0x2468
            mov ds, ax
            mov bx, 0xa
            
            mov  [bx], dx    
    
    skip:
main endp
.exit
