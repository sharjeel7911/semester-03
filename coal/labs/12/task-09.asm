;Newline, carriage return, and tab characters are not displayed, but they instruct the display function to perform specific operations. The newline character moves the cursor to the next row in the same column, while carriage return moves the cursor to the first column of the current row. Similarly, the tab character inserts eight spaces. Add the functionality of newline, cret, and tab to the print procedure you created in task 1. (Hint: See ASCII code of these characters from ASCII table) 
.model small
.stack 0x100
.data 
     msg db 'Sharjeel Ahmad', 0
     len equ $-msg
     row dw 1
     col dw 51
.code
main proc
    mov ax, @data
    mov ds, ax
    mov cx, len
    push offset msg
    push len
    push row 
    push col
    call printString
    add sp, 8 
;exit
mov ax, 0x4c00
int 0x21                                
main endp

;function definition
printString proc
    mov ax, 0xb800
    mov es, ax
    
    push bp
    mov bp, sp
    mov ax, [bp + 6] ;row
    mov bx, [bp + 4] ;col 
    
    mov cx, 80 ;2 * (Row address * 80 + Column address)
    mul cx
    add ax, bx
    shl ax, 1
    mov di, ax
    
    mov cx, [bp + 8] ;length of string
    ;dec cx ;loop starts from 15, while it should be 14 but because of logic of carrigeReturn func, i had to run the cx 15 times but it will run only 14 times if carrige func is running
    mov si, [bp + 10] ;offset string 
    
    printLoop:
              mov al, [si]
              carriage:
                       cmp cx, 0xd ;it doesn't work as intended which is when ascii char 0xd comes it jumps to col 0 but i implemeted same functionality for loop counter as if cx = 0xd, it will call the proc.  
                       je done
              mov es:[di], al
              mov al, 0x0a
              mov es:[di + 1], al 
              call tab
              call newLine
              inc si
              add di, 2    
    loop printLoop 
    jmp endPrint
    done:
         call carriageReturn
    loop printLoop 
    endPrint:
    pop bp 
    ret
printString endp        

;function definition
newLine proc
    add di, 158
    ret                         
newLine endp

;function definition
tab proc
    add di, 8
    ret                         
tab endp  

;function definition
carriageReturn proc
    push ax
    push dx
    push cx
    
    mov ax, di
    xor dx, dx        
    mov cx, 160
    div cx ;ax = current row number, dx = offset within row
    
    mov di, ax        
    mov cx, 160
    mul cx             
    mov di, ax        
    
    pop cx
    pop dx
    pop ax
    ret
carriageReturn endp    