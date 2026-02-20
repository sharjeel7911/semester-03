.model small 
.stack 0x100
.data       
     arr db 4,5,7,3,1,6,9,0,2,8
.code
main proc
    mov ax, @data 
    mov ds, ax
    
    mov bx, offset arr
    
    mov si, 0  
    mov cx, 9
    
    bubbleSort:
               mov di, cx
               mov si, 0
               
               
               innerLoop:
                         mov ah, 0 
                         mov al, arr[si] 
                         mov dl, arr[si + 1]
                         
                         cmp al, dl
                         jna skip
                         
                          
                         mov dh, al 
                         
                         mov arr[si], dl  
                         mov arr[si + 1], dh
                         
                         
                         
               skip:
               
               
                
               inc si
               dec di
                              
               cmp di, 0
               jne innerLoop
    
    loop bubbleSort
main endp
.exit
