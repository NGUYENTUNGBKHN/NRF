.thumb
.syntax unified


.type SVC_Handler, %function
.global SVC_Handler
SVC_Handler:
    mrs r0, psp
    
    stmdb r0!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    pop {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}
    msr psr, ip

    bx lr



.globl activates
activates:
    /*SAVE processor status */
    /*msr is move to register from system coprocessor */
    mrs  ip, psr

    push {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}

    /*Load user state */
    /*Why not use stack pointer */
    ldmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    /*msr is move to system coprocessor from register */
    msr psp, r0

    mov r0, #0xfffffff0
    cmp lr, r0

    ittt ls     /* ls is low same */
    movls   r0, #3
    msrls   control, r0
    isbls

    bx lr
