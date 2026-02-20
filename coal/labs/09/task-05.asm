;Write Procedure That Finds Maximum Number from an array.
.model small
.stack 0x100
.data
     arr dw 0x1, 0x20, 0x3, 0x5, 0x10 
     size dw 5
     max dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ax, offset arr
    push ax
    mov ax, size
    push ax
    mov ax, offset max
    push ax 
    call findMax
    add sp, 6
main endp
.exit     

;function definition
findMax proc
    push bp
    mov bp, sp
    
    mov si, [bp + 8] ;offset array
    mov cx, [bp + 6] ;size      
    mov dx, [bp + 4] ;offset max        

    mov ax, [si] ;first element = max             
    add si, 2
    dec cx
    
    maxNum:
           cmp cx, 0
           je storeResult
           mov bx, [si]       
           cmp bx, ax
           jle skip
           mov ax, bx
    skip:
         add si, 2
         dec cx
         jmp maxNum
    storeResult:
                mov bx, dx
                mov [bx], ax
    pop bp            
    ret
findMax endp    