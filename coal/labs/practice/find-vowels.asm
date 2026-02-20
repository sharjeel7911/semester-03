.model small
.stack 0x100
.data
     input  db 20 dup(?)
     count  dw 0
     msg0 db 'Enter String: $'
     ;0x0d, 0x0a -> means nextline combining (newline + carriage return [0x0d{carriage return}, 0x0a{newline}])[will move cursor on next line (next row, 0)]
     msg1 db 0x0d, 0x0a, 'Input stored.', 0x0d, 0x0a, 0x0d, 0x0a, 'Result:', 0x0d, 0x0a, '$'
     vowel  db ' : Vowel', 0x0d, 0x0a, '$'
     consonant   db ' : Consonant', 0x0d, 0x0a, '$'
.code
main proc
    mov ax, @data
    mov ds, ax

    xor bx, bx
    lea dx, msg0
    mov ah, 0x09
    int 0x21
    mov cx, 0            

    ;================= input =================
    takeInput:
              cmp cx, 20
              je inputDone
              
              mov ah, 0x01
              int 0x21

              cmp al, 0x0d           ; if Enter key?
              je inputDone

              ;check A - Z
              cmp al, 'A'
              jb takeInput
              cmp al, 'Z'
              jbe store

              ;check a - z
              cmp al, 'a'
              jb takeInput
              cmp al, 'z'
              ja takeInput
              
              ;convert to uppercase
              cmp al, 'a'
              jae makeUpper
              cmp al, 'z'
              jbe makeUpper

              store:
                    mov input[bx], al
                    inc bx
    inc cx                
    jmp takeInput
    makeUpper:      
              sub al, 0x20
              jmp store
    inputDone:
              mov count, bx
              
    mov dx, offset msg1
    mov ah, 0x09
    int 0x21

    ;============== process ==================  

    xor si, si

    processLoop:
               cmp si, count
               je exit

               mov al, input[si]
               mov dl, al
               mov ah, 0x02
               int 0x21 ;print character      

               cmp al, 'A'
               je isVowel
               cmp al, 'E'
               je isVowel
               cmp al, 'I'
               je isVowel
               cmp al, 'O'
               je isVowel
               cmp al, 'U'
               je isVowel

               isConsonant:
                           mov dx, offset consonant
                           jmp printResult

               isVowel:
                       mov dx, offset vowel

               printResult:
                           mov ah, 0x09
                           int 0x21
    inc si
    jmp processLoop
    
    exit:
;exit
mov ax, 0x4c00
int 0x21
main endp