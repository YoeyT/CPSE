.cpu cortex-m0
.text
.align 1

.global _start


//r0 = char, r4 = adress of msg, r5 = adress of buffer, r6 is buffer end adress
_start:
    push {lr}
    ldr r0, =compressed
    bl decompress
    pop {pc}



decompress:
    push {r4, r5, lr}
    mov r4, r0
    ldr r5, =buffer
loop:
    //load char on adress r4 into r0
    ldrb r0, [r4]

    //do calculation on r0, check if r0 is eof
    add r0, r0, #0
    beq done

    //if character == '@' branch to compressed_part else branch to add_to_buffer
    cmp r0, #64
    beq compressed_part

    bl add_to_buffer

loop_end:
    //increment memory adress by 1 for next char
    add r4, r4, #1
    b loop
done:
    pop {r4, r5, pc}



add_to_buffer:
    //push r6 and r7
    push {r4, r6, r7, lr}

    //r6 = buffer length -1 and r7 = buffer length
    mov r6, #99
    mov r7, #100
buffer_loop:
    //tmp value
    ldrb r4, [r5, r6]

    //shift buffer one byte to the right
    strb r4, [r5, r7]

    sub r6, r6, #1
    sub r7, r7, #1

    //loop is done if r7 == 0
    add r7, r7, #0
    bne buffer_loop

    //-------------------------------

    //change first byte in buffer to r0
    strb r0, [r5]

    //print r0
    bl uart_put_char

    pop {r4, r6, r7, pc}



compressed_part:
    push {r3, r6, r7}

    //the character '0'
    mov r3, #48

    //load offset into r6
    add r4, r4, #1
    ldrb r0, [r4]
    sub r6, r0, r3

    //load length into r7
    add r4, r4, #1
    ldrb r0, [r4]
    sub r7, r0, r3
compressed_part_loop:
    ldrb r0, [r5, r6]

    //add r0 to buffer
    bl add_to_buffer

    //do while length > 0
    sub r7, r7, #1
    bne compressed_part_loop
    
    pop {r3, r6, r7}

    //go back to original loop
    b loop_end


msg:
    .asciz "random text @73mee@;3@>3sten"

.data
buffer:
    .asciz "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"

@ .bss
@ compressedText:
@     =compressed
@ .skip 4200