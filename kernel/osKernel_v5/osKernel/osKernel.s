.thumb
.syntax unified

.global tcb_curr


.type Systick_Handler, %function
.global Systick_Handler
Systick_Handler:
    CPSID   i
    ldr r0, =tcb_curr
    ldr r1, [r0]
    str sp, [r1]
    ldr r1, [r1,#4]
    str r1, [r0]
    ldr sp, [r1]
    pop {r4, r5, r6, r7, r8, r9, r10, r11}
    CPSIE   i
    bx lr


.global osSchedulerLaunch
osSchedulerLaunch:
    ldr r0, =tcb_curr
    ldr r1, [r0]
    ldr sp, [r1]
    pop {r4, r5, r6, r7, r8, r9, r10, r11}
    pop {r0, r1, r2, r3}
    pop {r12}
    add sp, sp, #4
    pop {lr}
    add sp, sp, #4
    CPSIE   i
    bx lr




