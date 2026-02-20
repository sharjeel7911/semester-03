;Write a program that initializes two 3x4-size matrices and stores their sum in another matrix. 
.model small
.stack 0x100
.data
     m1 db 0x1, 0x2, 0x3, 0x4
        db 0x5, 0x6, 0x7, 0x8
        db 0x9, 0x0a, 0x0b, 0x0c
     m2 db 0x1, 0x1, 0x1, 0x1
        db 0x2, 0x2, 0x2, 0x2
        db 0x3, 0x3, 0x3, 0x3
     m3 db 12 dup(?)
.code
main proc
    mov ax, @data
    mov ds, ax

    xor bx, bx  
    rowLoop:
            cmp bx, 3
            jge exit
            xor cx, cx
            colLoop:
                    cmp cx, 4
                    jge nextRow
                    mov si, bx
                    shl si, 2          
                    add si, cx ;(row * 4) + col       

                    mov al, m1[si]
                    add al, m2[si]
                    mov m3[si], al
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