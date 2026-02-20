;Write a program that defines the procedure "SUM." The procedure receives three arrays: A, B, and C, and the sizes of the arrays through a parameter. The procedure addscorresponding elements from arrays A and B and stores the sum in array C. 
.model small 
.stack 0x100
.data
     arrA db 1, 2, 3, 4, 5
     arrB db 6, 7, 8, 9, 0
     arrC db 5 dup(0)
     size dw 5
.code
main proc 
    mov ax, @data
    mov ds, ax
    
    mov ax, offset arrA
    push ax
    mov ax, offset arrB
    push ax 
    mov ax, offset arrC
    push ax
    mov ax, size
    push ax
    
    call addArrays
    add sp, 8
main endp
.exit  

;function defination
addArrays proc
    push bp
    mov bp, sp
    
    mov cx, [bp + 4] ; array size
    mov bx, [bp + 6] ; arrC pointer

    xor si, si
    additionLoop:
                 mov ah, 0
                 mov al, [arrA + si] 
                 add al, [arrB + si]
                 mov [bx + si], al
                 
                 inc si
    loop additionLoop
    
    mov sp, bp
    pop bp                
    ret
addArrays endp        