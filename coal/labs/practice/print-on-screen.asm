.model small
.stack 0x100
.data
     msg db 'Sharjeel$'
     str db 'Ahmad$'
.code 
main proc 
    mov ax, @data
    mov ds, ax   
    
    ;------------------ DOS printing ------------------ 
    
    ;set cursor
    mov ah, 0x02
    mov bh, 0x00 ;page number
    mov dh, 1 ;row
    mov dl, 0 ;col
    int 0x10 
    
    xor dx, dx
    
    ;get cursor position
    mov ah, 0x03
    mov bh, 0x00 ;page number
    int 0x10 
    
    ;print string on screen
    mov dx, offset msg
    mov ah, 0x09   
    int 0x21
    
    ;This does two things:
    ;Screen contents move up by 1 row
    ;A blank line appears at the bottom

    ;But the cursor position is NOT updated automatically, so visually:
    ;Your printed text moves up
    ;Cursor stays where it was logically   
    
    mov ah, 0x06
    mov al, 1 ;scroll 1 line up
    mov bh, 0x07 ;attribute of blank (white on black)
    mov cx, 0x0000 ;upper-left (0,0) 
    mov dx, 0x184f ;lower-right (24,79)
    int 0x10 ;from (0,0) to (24,79) -> whole screen
    
    ;newline insert on same col but next row
    mov dl, 0x0a   
    mov ah, 0x02
    int 0x21 
    
    ;print string on screen
    mov dx, offset str
    mov ah, 0x09
    int 0x21
         
    ;carriage return will move cursor to (same row, col = 0)
    mov dl, 0x0d   
    mov ah, 02h
    int 0x21    
    
    ;print string on screen
    mov dx, offset str
    mov ah, 0x09
    int 0x21 
    
    ;set cursor
    mov ah, 0x02
    mov bh, 0x00 ;page number
    mov dh, 1 ;row
    mov dl, 0 ;col
    int 0x10 
    
    ;print string on screen
    mov dx, offset str
    mov ah, 0x09
    int 0x21 
    
    ;-------------------- Video memory ------------------

    mov ax, 0xb800 
    mov es, ax
    
    mov si, offset msg ; (3 * 80 + 0) * 2
    mov di, 480          
    
    mov cx, 8 
    vidMem:
           movsb
           mov al, 0x0e
           mov es:[di], al    
           inc di
    loop vidMem  
    
    
    
    mov si, offset str ; (4 * 80 + 0) * 2
    mov di, 640
    mov cx, 5
    
    vidM:
           movsb
           mov al, 0x0e
           mov es:[di], al    
           inc di
    loop vidM      
;exit
mov ax, 0x4c00
int 0x21
main endp    