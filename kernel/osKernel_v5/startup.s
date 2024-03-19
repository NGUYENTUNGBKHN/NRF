
.syntax unified
.arch armv7e-m
.thumb              @ thumb instruction

    .global _estack

    .section .isr_vector, "ax"
    .align 2
    .global __isr_vector
__isr_vector:
    .long   _estack
    .long   Reset_Handler
    .long   0

    .size __isr_vector, . - __isr_vector

    .text
    .thumb
    .thumb_func
    .align 1
    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    bl main

    .pool
    .size Reset_Handler, . - Reset_Handler


.end

