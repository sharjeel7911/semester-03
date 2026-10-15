;Write Procedure That Finds Minimum Number from an array.
.model small
.stack 0x100
.data
     arr dw 0x10, 0x20, 0x3, 0x5, 0x10 
     size dw 5
     min dw 0
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ax, offset arr
    push ax
    mov ax, size
    push ax
    mov ax, offset min
    push ax 
    call findMin
    add sp, 6
main endp
.exit     

;function definition
findMin proc
    push bp
    mov bp, sp
    
    mov si, [bp + 8] ;offset array
    mov cx, [bp + 6] ;size      
    mov dx, [bp + 4] ;offset min        

    mov ax, [si] ;first element = min             
    add si, 2
    dec cx
    
    minNum:
           cmp cx, 0
           je storeResult
           mov bx, [si]       
           cmp bx, ax
           jge skip
           mov ax, bx
    skip:
         add si, 2
         dec cx
         jmp minNum
    storeResult:
                mov bx, dx
                mov [bx], ax
    pop bp            
    ret
findMin endp    