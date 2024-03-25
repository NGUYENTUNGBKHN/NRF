.thumb
.syntax unified



.macro  save_kernal_state
    mrs ip, psr @ mov ip from psr
    push {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}
.endm

.type SVC_Handler, %function
.global SVC_Handler
SVC_Handler:
    mrs r0, psp         @ mov r0 from psp
    @ store r4 -> lr to [r0]                    
    stmdb r0!, {r4, r5, r6, r7, r8, r9, r10, r11, lr} 

    pop {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}
    msr psr, ip
    bx lr


.global activate
activate:
    /* SAVE kernal state */
    save_kernal_state

    ldmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    msr psp, r0 @ mov psp from r0

    bx lr



.global init_kernel
init_kernel:
    /* SAVE kernal state */
    save_kernal_state

    /* switch to thread mode */
    msr psp, r0         @ mov psp from r0;
    mov r0, #3         @ r0 = 3
    msr control, r0     @ control = 3, select thread mode
    isb                 @ 
    bl syscall          @ jump to syscall
    bx lr               @ return back




