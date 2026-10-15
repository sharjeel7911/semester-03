;Write a program that declares and initializes an array of 20 elements and then calculates the number of occurrences of a specific number in the array.
.model small
.stack 0x100
.data
     array db 1, 2, 3, 4, 5, 3, 2, 1, 3, 5, 1, 2, 3, 4, 3, 2, 1, 5, 3, 3  
     target db 3     
     count  db 0  
.code
main proc
    mov ax, @data
    mov ds, ax

    mov si, 0       
    xor cx, cx      

    countLoop:
              cmp si, 20
              jae done        

              mov al, array[si]  
              cmp al, target
              jne skipIncrement
              inc cx              ; found target, increment counter

              skipIncrement:
                            inc si
    jmp CountLoop

    done:
         mov count, cl
;exit
mov ax, 0x4c00
int 0x21
main endp