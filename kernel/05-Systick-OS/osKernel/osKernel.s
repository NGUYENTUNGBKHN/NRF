.syntax unified
.arch armv7e-m
.thumb
.global tcb_curr

.text
.align 2
.type Systick_Handler, %function
.global Systick_Handler
Systick_Handler:
    CPSID   i                                   @ disable interrupt    
    push {r4, r5, r6, r7, r8, r9, r10, r11}     @ Save r4 r11 into old sp 
    ldr r0, =tcb_curr                           @ r0 = tcb_curr
    ldr r1, [r0]                                @ r1 = *tcb_curr
    str sp, [r1]                                @ stackPt = sp
    ldr r1, [r1,#4]                             @ r1 = next
    str r1, [r0]                                @ curr = next
    ldr sp, [r1]                                @ sp = *next = m_tcb[next]
    pop {r4, r5, r6, r7, r8, r9, r10, r11}      @ Set r4 r11
    CPSIE   i                                   @ enable interrupt
    bx lr


.global osSchedulerLaunch
osSchedulerLaunch:
    ldr r0, =tcb_curr                           @ r0 = tcb_curr  Load address tcb_curr into r0
    ldr r2, [r0]                                @ r2 = *tcb_curr Load value of tcb_curr into r2
    ldr sp, [r2]                                @ sp = stackPt   Load address stackPt into sp (stack pointer)
    pop {r4, r5, r6, r7, r8, r9, r10, r11}      @ Set r4 - r11
    pop {r0, r1, r2, r3}                        @ Set r0
    pop {r12}                                   @ Set r12
    add sp, sp, #4                              @ Skip sp
    pop {lr}                                    @ Set lr
    add sp, sp, #4                              @ skip PC
    CPSIE   i                                   @ enable interrupt
    bx lr

