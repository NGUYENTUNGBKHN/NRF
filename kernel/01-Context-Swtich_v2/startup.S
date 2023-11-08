

    .syntax unified
    .arch armv7e-m

#define __STARTUP_CONFIG_STACK_SIZE__       0x1000
#define __STARTUP_CONFIG_STACK_ALIGNEMENT__ 3
#define __STARTUP_CONFIG_HEAP_SIZE__          0x1000

    /* STACK space */
    .section .stack
    .align __STARTUP_CONFIG_STACK_ALIGNEMENT__
    .equ Stack_Size, __STARTUP_CONFIG_STACK_SIZE__
    .global __StackTop
    .global __StackLimit
__StackLimit:
    .space Stack_Size
    .size __StackLimit, . - __StackLimit
__StackTop:
    .size __StackTop, . - __StackTop
    /* HEAP space */
    .section .heap
    .align 3
    .equ Heap_Size, __STARTUP_CONFIG_HEAP_SIZE__
    .global __HeapBase
    .global __HeapLimit
__HeapBase:
    .space Heap_Size
    .size __HeapBase, . - __HeapBase
__HeapLimit:
    .size __HeapLimit, . - __HeapLimit
    /* VECTOR table */
    .section .irs_vector, "ax"
    .align 2
    .global __isr_vector
__isr_vector:
    .long   __StackTop
    .long   Reset_Handler
    .long   NMI_Handler
    .long   HardFault_Handler
    .long   0

    .size __isr_vector, . - __isr_vector


    /* Reset Handler */
    .text
    .thumb
    .thumb_func
    .align 1
    .global Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    ldr r1, =__extext
    ldr r2, =__data_start__
    ldr r3, =__bss_start__

    subs r3, r3, r2
    ble .L_loop1_done

.L_loop1:
    subs r3, r3, #4
    ldr r0, [r1,r3]
    str r0, [r2,r3]

.L_loop1_done:






