/*
 * Module: arm64-Output.S
 * Function: arm64_printFMT
 * Description: Low-level formatted output for ARM64 using raw syscalls.
 */
.section .bss, "aw", @nobits
    .balign 64
    .type buffer, %object
buffer:
    .skip 24
    .size buffer, .-buffer
.section .data, "aw", @progbits
    .balign 64
    .type exp, %object
exp:
    .ascii "%"
    .size exp, .-exp
.section .text, "ax", @progbits
    .balign 64
    .global arm64_printFMT
    .global plugin_string
    .global plugin_u64
    .type arm64_printFMT, %function
    .type plugin_string, %function
    .type plugin_u64, %function
arm64_printFMT:
    stp x29, x30, [sp, #-160]!
    stp x19, x20, [sp, #16]
    stp x1, x2, [sp, #32]
    stp x3, x4, [sp, #48]
    stp x5, x6, [sp, #64]
    str x7, [sp, #80]
    mov x29, sp
    mov x19, x0
    add x20, sp, #32
loopMain:
    ldrb w9, [x19], #1
    cbz w9, endFunc
    subs wzr, w9, #'%'
    beq handle_format
    movz x0, #1
    sub x1, x19, #1
    movz x2, #1
    movz x8, #64
    svc #0
    b loopMain
handle_format:
    ldrb w9, [x19], #1
    subs wzr, w9, #'s'
    beq if_s
    subs wzr, w9, #'d'
    beq if_d
    movz x0, #1
    adrp x1, exp
    add x1, x1, #:lo12:exp
    movz x2, #1
    movz x8, #64
    svc #0
    b loopMain
if_s:
    ldr x0, [x20], #8
    bl plugin_string
    b loopMain
if_d:
    ldr x0, [x20], #8
    bl plugin_u64
    b loopMain
endFunc:
    ldp x29, x30, [sp], #16
    ldp x19, x20, [sp], #144
    ret
    .size arm64_printFMT, .-arm64_printFMT

plugin_string:
    stp x29, x30, [sp, #-16]!
    mov x1, x0
loop:
    ldrb w9, [x0], #1
    cbnz w9, loop
    sub x2, x0, x1
    sub x2, x2, #1
    movz x0, #1
    mov x8, #64
    svc #0
    ldp x29, x30, [sp], #16
    ret
    .size plugin_string, .-plugin_string

plugin_u64:
    stp x29, x30, [sp, #-48]!
    stp x19, x20, [sp, #16]
    stp x21, x22, [sp, #32]
    mov x29, sp
    adrp x21, buffer
    add x21, x21, #:lo12:buffer
    add x21, x21, #23
    mov x19, x0
    mov x20, #10
    mov x22, xzr
u64_loop:
    udiv x9, x19, x20
    msub x10, x9, x20, x19
    mov x19, x9
    add w10, w10, #48
    strb w10, [x21]
    add x22, x22, #1
    cbz x19, u64_print
    sub x21, x21, #1
    b u64_loop
u64_print:
    mov x0, #1
    mov x1, x21
    mov x2, x22
    mov x8, #64
    svc #0
u64_done:
    ldp x21, x22, [sp, #32]
    ldp x19, x20, [sp, #16]
    ldp x29, x30, [sp], #48
    ret
    .size plugin_u64, .-plugin_u64
