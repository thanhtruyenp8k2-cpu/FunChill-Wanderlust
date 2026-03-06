.section .text, "ax", @progbits
    .balign 64
    .global print_string
    .type print_string, %function
print_string:
    mov x1, x0
loop:
    ldrb w9, [x0], #1
    cbnz w9, loop
    sub x2, x0, x1
    sub x2, x2, #1
    movz x0, #1
    mov x8, #64
    svc #0
    ret
    .size print_string, .-print_string
