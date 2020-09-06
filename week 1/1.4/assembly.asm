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
    b change_char
mid_loop:
    bl uart_put_char
    add r5, r5, #1
    b loop
done:
    pop { r5, pc }

change_char:
    cmp r0, #97
    bge lower_check
    cmp r0, #65
    bge upper_check
    b mid_loop

upper_check:
    cmp r0, #90
    bls upper
    b mid_loop
upper:
    add r0, r0, #32
    b mid_loop

lower_check:
    cmp r0, #122
    bls lower
    b mid_loop
lower:
    sub r0, r0, #32
    b mid_loop


msg:
    .asciz "Hello world, the ANSWER is 42!@[ ]`{}\n"