
.syntax unified
.arch armv7e-m
@ .thumb              @ thumb instruction

    .global _estack

    .section .isr_vector, "ax"
    .align 2
    .global __isr_vector
__isr_vector:
    .long   _estack
    .long   Reset_Handler
    .long   NMI_handler
    .long   HardFault_handler
    .long   MemoryMntFault_handler
    .long   BusFault_handler
    .long   UsageFault_handler
    .long   0
    .long   0
    .long   0
    .long   0
    .long   SVC_Handler

    .size __isr_vector, . - __isr_vector

    .text
    .thumb
    .thumb_func
    .align 1
    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:

    /* Copy data section */
    ldr r1, =_sdata
    ldr r2, =_edata
    ldr r3, =_sidata

    movs r0, 0

    subs r2, r2, r1
    ble _L_loop1_done

_L_loop1:
    subs r2, r2, #4
    ldr r0, [r3, r2]
    str r0, [r1, r2]
    bgt _L_loop1

_L_loop1_done:

    /* set bss 0 */
    ldr r1, =_sbss
    ldr r2, =_ebss

    movs r0, 0

    subs r2, r2, r1
    ble _L_loop2_done

_L_loop2:
    subs r2, r2, #4
    str r0, [r1, r2]
    bgt _L_loop2

_L_loop2_done:

    bl main

    .pool
    .size Reset_Handler, . - Reset_Handler


    .section ".text"

    /* NMI  */
    .weak NMI_handler
    .type NMI_handler, %function
NMI_handler:
    b   .
    .size NMI_handler, . - NMI_handler

    /* Hard Fault  */
    .weak HardFault_handler
    .type HardFault_handler, %function
HardFault_handler:
    b   .
    .size HardFault_handler, . - HardFault_handler

    /* MEMORY management fault*/
    .weak MemoryMntFault_handler
    .type MemoryMntFault_handler, %function
MemoryMntFault_handler:
    b   .
    .size MemoryMntFault_handler, . - MemoryMntFault_handler

    .weak BusFault_handler
    .type BusFault_handler, %function
BusFault_handler:
    b   .
    .size BusFault_handler, . - BusFault_handler

    .weak UsageFault_handler
    .type UsageFault_handler, %function
UsageFault_handler:
    b   .
    .size UsageFault_handler, . - UsageFault_handler

    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    b   .
    .size SVC_Handler, . - SVC_Handler

.end

