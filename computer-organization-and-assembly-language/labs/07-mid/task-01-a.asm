.model small 
.stack 0x100
.data
     num dw 0xffee
.code
main proc
    mov ax, @data 
    mov ds, ax
    
    mov ax, num
    
    xor bx, bx
    mov cx, 16
    
    reverseNum:
               
               rcr ax, 1
               rcl bx, 1
                
    loop reverseNum
    
main endp
.exit
