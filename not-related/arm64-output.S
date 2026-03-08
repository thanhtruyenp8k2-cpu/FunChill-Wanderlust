/*
 * arm64-output.S - Low-level formatted output for ARM64
 *
 * Copyright (C) 2025-2026 truyen@localhost
 * Part of the FunChill-Wanderlust Project
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file arm64-output.S
 * @brief ARM64 Variadic Print Implementation using raw Linux Syscalls.
 * * This module provides a standalone formatted output utility optimized
 * for Termux environments, avoiding dependencies on standard C libraries.
 * It features a stack-aware pointer logic to handle 16-byte alignment
 * constraints on the ARM64 architecture. 
 *
 * Architecture: ARM64 (AArch64) 
 * Syscall Interface: Linux Write (64) 
 * * @author truyen@localhost
 * @date 2026-03-08
 */
#ifndef ARM64__OUTPUT__S
#define ARM64__OUTPUT__S
#ifndef __ANDROID__
# error Architecture not supported
#endif
#ifndef __aarch64__
# error Architecture not supported
#endif
.section .bss, "aw", @nobits
    .balign 64
    .type buffer, %object
buffer:
    .skip 24
    .size buffer, .-buffer
.section .data, "aw", @progbits
    .balign 64
    .type percent_format, %object
percent_format:
    .ascii "%"
    .size percent_format, .-percent_format
.section .text, "ax", @progbits
    .balign 64
    .global arm64_print
    .global string_plugin
    .global unsigned_decimal_utility
    .type arm64_print, %function
    .type string_plugin, %function
    .type unsigned_decimal_utility, %function
arm64_print:
    stp x29, x30, [sp, #-96]!
    stp x19, x20, [sp, #16]
    stp x1, x2, [sp, #32]
    stp x3, x4, [sp, #48]
    stp x5, x6, [sp, #64]
    str x7, [sp, #80]
    add x29, sp, #88
    mov x19, x0
    add x20, sp, #32
format_string_processing:
    ldrb w9, [x19], #1
    cbz w9, end_output
    subs wzr, w9, #'%'
    beq format_handling
    movz x0, #1
    sub x1, x19, #1
    movz x2, #1
    movz x8, #64
    svc #0
    b format_string_processing
format_handling:
    ldrb w9, [x19], #1
    subs wzr, w9, #'s'
    beq string
    subs wzr, w9, #'d'
    beq decimal
    movz x0, #1
    adrp x1, percent_format
    add x1, x1, #:lo12:percent_format
    movz x2, #1
    movz x8, #64
    svc #0
    b format_string_processing
string:
    subs xzr, x20, x29
    beq exception_0
    ldr x0, [x20], #8
    bl string_plugin
    b format_string_processing
exception_0:
    add x20, x20, #8
    b string
decimal:
    subs xzr, x20, x29
    beq exception_1
    ldr x0, [x20], #8
    bl unsigned_decimal_utility
    b format_string_processing
exception_1:
    add x20, x20, #8
    b decimal
end_output:
    ldp x29, x30, [sp], #16
    ldp x19, x20, [sp], #80
    ret
    .size arm64_print, .-arm64_print
string_plugin:
    stp x29, x30, [sp, #-16]!
    mov x1, x0
string_processing:
    ldrb w9, [x0], #1
    cbnz w9, string_processing
    sub x2, x0, x1
    sub x2, x2, #1
    movz x0, #1
    mov x8, #64
    svc #0
    ldp x29, x30, [sp], #16
    ret
    .size string_plugin, .-string_plugin
unsigned_decimal_utility:
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
unsigned_decimal_processing:
    udiv x9, x19, x20
    msub x10, x9, x20, x19
    mov x19, x9
    add w10, w10, #48
    strb w10, [x21]
    add x22, x22, #1
    cbz x19, unsigned_decimal_output
    sub x21, x21, #1
    b unsigned_decimal_processing
unsigned_decimal_output:
    mov x0, #1
    mov x1, x21
    mov x2, x22
    mov x8, #64
    svc #0
end_of_decimal_label_without_sign:
    ldp x21, x22, [sp, #32]
    ldp x19, x20, [sp, #16]
    ldp x29, x30, [sp], #48
    ret
    .size unsigned_decimal_utility, .-unsigned_decimal_utility
.section .note.GNU-stack, "x", @progbits
.section .note.ABI-tag, "a", @note
    .balign 4
    .long 4, 16, 1
    .asciz "GNU"
    .long 0, 3, 7, 0
.ident "GCC: (GNU) 15.2.1 20260103"
.ident "GCC: (crosstool-NG 1.28.0.3_a3fef85) 15.2.1 20260103"
.section .note.gnu.build-id,"a",@note
    .balign 4
    .long 4, 20, 3
    .asciz "GNU"
    .byte 0x39, 0xe7, 0x8f, 0x79, 0xa9, 0xc1, 0xe1, 0x10, 0x50, 0x16
    .byte 0xe4, 0x1a, 0x60, 0x57, 0x2f, 0x42, 0x73, 0x9d, 0xdc, 0x63
#endif
