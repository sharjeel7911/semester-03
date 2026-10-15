.model small
.stack 0x100
.data
     str db 'Sharjeel$' ;'Sharjeel', 0 won't work for dos  
     len equ $-str
.code
main proc 
    mov ax, @data
    mov ds, ax   
    
    mov ax, 0x2000
    mov es, ax
    
    mov di, 0
    mov si, offset str   
    mov cx, len
    
    cld ;forward direction of directional flag 
    ;std ;it will set drectional flag which will read the string in reverse
    storeLoop:
              lodsb ;al = [ds : si]   
              stosb ;[es : di] = al  
              ;movsb ;this single instrunction will work the same [es : di] = [ds : si]
    loop storeLoop 
    
    ;rep(repeat) keyword will run the instruction cx time, same as loop 
    ;mov cx, len                     
    ;rep movsb ;no need for loop, this single instrunction will work the same [es : di] = [ds : si]     
                           
    ;load the string from es and display on screen with dos interrupt 
    mov ax, es
    mov ds, ax    
    
    mov di, 0
    mov dx, 0x0
    mov ah, 0x09
    int 0x21 
;exit    
mov ax, 0x4c00
int 0x21
main endp    