;Write a program that declares and initializes a 3x4-sized matrix M1, takes its transpose, and stores the transpose in another matrix M2.     
.model small 
.stack 0x100
.data
     m1 db 0x1, 0x2, 0x3, 0x4
        db 0x5, 0x6, 0x7, 0x8
        db 0x9, 0xa, 0xb, 0xc
     m2 db 12 dup(?)   
.code
main proc
    mov ax, @data 
    mov ds, ax 
    
    xor bx, bx ;rows
    rowLoop:
            cmp bx, 3
            jge exit
            xor cx, cx ;cols
            colLoop:     
                    cmp cx, 4           
                    jge nextRow   
                    
                    ;access element
                    mov si, bx
                    shl si, 2 ;row * 4
                    add si, cx ;(row * 4) + col
                    mov al, m1[si]
            
                    ;copy to m2
                    mov di, cx ;di = current col
                    mov dx, di ;save di
                    shl di, 1 ;col * 2
                    add di, dx ;col * 3 [for ex. if col = 3 -> 3 * 2 = 6 -> 6 + dx = 9 -> equivalent to col * 3]
                    add di, bx ;(col * 3) + row [transpose logic [row][col] = [col][row]] 
                    mov m2[di], al
                    inc cx
            jmp colLoop
            nextRow:                    
                    inc bx
    jmp rowLoop
    exit: 
;exit
mov ax, 0x4c00
int 0x21    
main endp