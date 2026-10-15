;You have an array: arr db 1,2,3,4,5. Push all 5 values onto the stack, then pop them into another array: rev db 5 dup(?)
.model small
.stack 0x100
.data
     arr db 1,2,3,4,5
     rev db 5 dup(?)
.code
main proc
    mov ax, @data 
    mov ds, ax
    
    mov si, 0
    mov cx, 5
    pushLoop:
             mov ah, 0
             mov al, [arr + si]
             push ax
             inc si
    loop pushLoop
    
    mov si, 0
    mov cx, 5
    popLoop:         
            pop ax
            mov [rev + si], al
            inc si
    loop popLoop        
main endp
.exit 