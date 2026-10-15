.model small
.stack 0x100
.data
     num db 0x8 ;we can safely calculate upto 8 otherwise overflow occurs in 16 bit number
     output dw ?
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov ah, 0
    mov al, num
    push ax
    mov ax, offset output
    push ax
    call factorial
    
    add sp, 4          
              
main endp
.exit   

factorial proc
    push bp
    mov bp, sp
    mov ax, [bp + 6]
    
    mov cx, ax
    mov ax, 1
    cmp cx, 0
    jz facDone
    
    calFac: 
           mul cx
           loop calFac
    facDone:
            mov di, [bp + 4]
            mov [di], ax 
            
            mov sp, bp
            pop bp
            
    ret
factorial endp    