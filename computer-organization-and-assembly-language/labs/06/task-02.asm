;bubble sort ->Write a program that declares and initializes a word-type array of 20 elements and sorts it using any sorting algorithm of your choice. 
.model small
.stack 0x100
.data   
     arr db 15, 12, 3, 10, 5, 6, 3, 8, 9, 43, 5, 87, 54, 33, 100, 99, 35, 0, 44, 65
.code
main proc
    mov ax, @data
    mov ds, ax
    
    mov cx, 19
    bubbleSort:
               mov si, 0      
               mov di, cx
                
               innerLoop:
                         mov al, arr[si]
                         mov bl, arr[si + 1]
                         cmp al, bl
                         jna noSwap
                         mov arr[si + 1], al
                         mov arr[si], bl  
               
                         noSwap:
                                inc si
               dec di
               jnz innerLoop
    loop bubbleSort    
main endp
.exit