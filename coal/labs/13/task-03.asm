;Write a program that initializes two 3x4 and 4x3-size matrices, named A and B, and stores the result after multiplication of A and B into a third matrix, C.
.model small
.stack 0x100
.data
     a db 1, 2, 3, 4
       db 5, 6, 7, 8
       db 9, 1, 2, 3
     b db 1, 2, 3
       db 4, 5, 6
       db 7, 8, 9
       db 1, 2, 3
     c db 9 dup(?)
.code
main proc
    mov ax, @data
    mov ds, ax

    xor bx, bx ;i = row index of a (0)   
    rowLoop:
            cmp bx, 3
            jge exit
            xor cx, cx ;j = column index of b (0)
            colLoop:
                    cmp cx, 4
                    jge nextRow
                    xor dx, dx ;sum = 0             
                    xor si, si ;k = 0          
                    mulLoop:
                            cmp si, 4
                            jge storeResult
                            
                            mov di, bx
                            shl di, 2 ;i * 4
                            add di, si ;(i * 4) + k
                            mov al, a[di]  
                            
                            mov di, si
                            mov bp, di
                            shl di, 1 ;k * 2
                            add di, bp ;k * 3
                            add di, cx;(k * 3) + j
                            mul b[di] ;al * b[k][j] -> ax
                            add dx, ax ;sum += product
                            inc si
                    jmp mulLoop
                    
                    storeResult:
                                mov di, bx
                                mov bp, di
                                shl di, 1 ;i * 2
                                add di, bp ;i * 3
                                add di, cx ;(i * 3) + j
                                mov c[di], dl ;store result 
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