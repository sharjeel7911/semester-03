;Write a program that first moves the cursor to the middle of screen, then prints a string "SHARJEEL" at that position
.model small
.stack 0x100
.data
     msg db "SHARJEEL$"
.code
main proc
    mov ax, @data
    mov ds, ax 

    mov ah, 0x02         
    mov bh, 0           
    mov dh, 12 ;2 * (12 * 80 + 40) = 2000
    mov dl, 35 ;not exactly center, that would be 40        
    int 0x10
    
    mov si, offset msg
    printLoop:
              lodsb                
              cmp al, '$'              
              je done             
              mov ah, 0x09           
              mov bh, 0             
              mov bl, 0x24   
              mov cx, 1         
              int 0x10 
    
              mov ah, 0x02      
              mov bh, 0          
              inc dl ;move cursor on next col            
              int 0x10
    jmp printLoop
    done:
;exit
mov ax, 0x4c00
int 0x21
main endp