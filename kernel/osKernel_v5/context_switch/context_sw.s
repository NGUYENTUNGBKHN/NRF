.thumb
.syntax unified

.global activate
activate:
    /* Save kernel state */
    mrs ip, psr
    push {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}

    /* swtich to process stack */
    msr psp, r0
    mov r0, #3
    msr control, r0

    /* load user state */
    pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}

    bx lr



