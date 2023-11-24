
    .syntax unified
    .arch armv7e-m

    /*STACK space */
    .section .stack
    .align      3
    .equ Stack_Size, 0x1000
    .globl __StackTop
    .globl __StackEnd
__StackEnd:
    .space Stack_Size
    .size __StackEnd, . - __StackEnd
__StackTop:
    .size __StackTop, . - __StackTop

    /* HEAP space */
    .section .heap
    .align      3
    .equ Heap_Size, 0x1000
    .globl __HeapBase
    .globl __HeapEnd
__HeapBase:
    .space Heap_Size
    .size __HeapBase, . - __HeapBase
__HeapEnd:
    .size __HeapEnd, . - __HeapEnd

    /*VECTOR table */
    .section .isr_vector, "ax"
    .align 2
    .globl  __isr_vector
__isr_vector:
    .long   _estack
    .long   Reset_Handler
    .long   NMI_Handler
    .long   HardFault_Handler
    .long   MemManage_Handler
    .long   BusFault_Handler
    .long   UsageFault_Handler
    .long   0
    .long   0
    .long   0
    .long   0
    .long   SVC_Handler

    .size __isr_vector, . - __isr_vector


    /* Reset Handler */
    .text
    .thumb
    .thumb_func
    .align 1
    .globl  Reset_Handler
    .type Reset_Handler, %function
Reset_Handler:
    ldr r1, =_sidata   @ r1 = __sidata
    ldr r2, =_sdata    @ r2 = __sdata
    ldr r3, =_edata    @ r3 = __edata

    subs r3, r3, r2
    ble .L_loop1_done

.L_loop1:
    subs r3, r3, #4
    ldr r0, [r1,r3]
    str r0, [r2,r3]
    bgt .L_loop1
    
.L_loop1_done:

    /* SET .bss segment 0 */
    ldr r1, =_sbss
    ldr r2, =_ebss

    movs r0, 0
    subs r2, r2, r1     @ r2 = r2 - r1
    ble .L_loop2_done

.L_loop2:
    subs r2, r2, #4     @ r2 = r2 - 1 (4byte)
    str r0, [r1,r2]     @ address of (r1 + r2) = 0
    bgt .L_loop2

.L_loop2_done:

    bl main

    .pool
    .size       Reset_Handler,. - Reset_Handler

    .section ".text"

    .weak   NMI_Handler
    .type   NMI_Handler, %function
NMI_Handler:
    b       .
    .size   NMI_Handler, . - NMI_Handler


    .weak   HardFault_Handler
    .type   HardFault_Handler, %function
HardFault_Handler:
    b       .
    .size   HardFault_Handler, . - HardFault_Handler


    .weak   MemManage_Handler
    .type   MemManage_Handler, %function
MemManage_Handler:
    b       .
    .size   MemManage_Handler, . - MemManage_Handler


    .weak   BusFault_Handler
    .type   BusFault_Handler, %function
BusFault_Handler:
    b       .
    .size   BusFault_Handler, . - BusFault_Handler


    .weak   UsageFault_Handler
    .type   UsageFault_Handler, %function
UsageFault_Handler:
    b       .
    .size   UsageFault_Handler, . - UsageFault_Handler

    .weak   SVC_Handler
    .type   SVC_Handler, %function
SVC_Handler:
    b       .
    .size   SVC_Handler, . - SVC_Handler

.end


