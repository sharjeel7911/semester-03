;Write a procedure: sum3 PROC. Main should push: 5, 10, 20. Procedure should: Access parameters using BP, Add all three, Return result in AX (do not use pop)
.model small
.stack 0x100
.data
.code
main proc
    push 5
    push 10
    push 20
    call sumThree
    add sp, 6
main endp
.exit 

;function definition
sumThree proc
    push bp
    mov bp, sp
    
    mov ax, [bp + 8]
    add ax, [bp + 6]
    add ax, [bp + 4]
    pop bp
    ret
sumThree endp    