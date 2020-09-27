.cpu cortex-m0
.text
.align 1

.global application

application:
    push { lr }
    ldr r0, =msg
    bl print_asciz
    pop { pc }
 
print_asciz:
    push { r5, lr }
    mov r5, r0
loop:
    ldrb r0, [ r5 ]
    add r0, r0, #0
    beq done
    bl change_char
    bl uart_put_char
    add r5, r5, #1
    b loop
done:
    pop { r5, pc }

change_char:
    push { lr }
    cmp r0, #97
    bge lower_check
    cmp r0, #65
    bge upper_check
done_change_char:
    pop { pc }


upper_check:
    cmp r0, #90
    bls upper
    b done_change_char

upper:
    add r0, r0, #32
    b done_change_char


lower_check:
    cmp r0, #122
    bls lower
    b done_change_char

lower:
    sub r0, r0, #32
    b done_change_char



msg:
    .asciz "Hello world, the ANSWER is 42!@[ ]`{}\n"