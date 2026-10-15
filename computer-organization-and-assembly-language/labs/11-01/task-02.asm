;Write an assembly language program to input a two-digit number and determine whether the sum of its digits is even or odd. -> 12 = 1+2 = 3, odd
.model small
.stack 0x100
.data
     msg1 db 'Enter two-digit number: $'
     msgEven db 'EVEN$'
     msgOdd  db 'ODD$'
     msgPlus db ' + $'
     msgEq   db ' = $'
     msgCol  db ' -> $'
     d1 db ?
     d2 db ?
     sum db ?
.code
main proc
    mov ax, @data
    mov ds, ax

; ---------- Prompt ----------
    mov dx, offset msg1
    mov ah, 0x09
    int 0x21

; ---------- Input First Digit ----------
    mov ah, 0x01
    int 0x21
    sub al, '0'
    mov d1, al

; ---------- Input Second Digit ----------
    mov ah, 0x01
    int 0x21
    sub al, '0'
    mov d2, al

; ---------- Sum Digits ----------
    mov al, d1
    add al, d2
    mov sum, al

; ---------- New Line ----------
    mov ah, 0x02
    mov dl, 0x0D
    int 0x21
    mov dl, 0x0A
    int 0x21

; ---------- Display d1 ----------
    mov al, d1
    add al, '0'
    mov dl, al
    mov ah, 0x02
    int 0x21

; ---------- Display '+' ----------
    mov dx, offset msgPlus
    mov ah, 0x09
    int 0x21

; ---------- Display d2 ----------
    mov al, d2
    add al, '0'
    mov dl, al
    mov ah, 0x02
    int 0x21

; ---------- Display '=' ----------
    mov dx, offset msgEq
    mov ah, 0x09
    int 0x21

; ---------- Display sum ----------
    mov al, sum
    add al, '0'
    mov dl, al
    mov ah, 0x02
    int 0x21

; ---------- Display ':' ----------
    mov dx, offset msgCol
    mov ah, 0x09
    int 0x21

; ---------- Check Even or Odd ----------
    mov al, sum
    and al, 0x01
    cmp al, 0x00
    je even

    odd:
        mov dx, offset msgOdd
        mov ah, 0x09
        int 0x21
        jmp exit

    even:
         mov dx, offset msgEven
         mov ah, 0x09
         int 0x21 
    exit:
;exit
mov ax, 0x4C00
int 0x21
main endp