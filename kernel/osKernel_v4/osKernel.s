        AREA | .text|, CODE, READONLY, ALIGN=2
        THUMB
        EXTERN tcb_curr
        export SysTick_Handler
        export osSchedulerLaunch

SysTick_Handler
    CPSID   I               ; disable interrupt
    PUSH    {R4-R11}        ; Save 
    LDR     R0, =tcb_curr   ; R0 = tcb_curr
    LDR     R1, [R0]        ; R1 = *tcb_curr
    STR     SP, [R1]        ; 


    CPSIE   I               ; enable interrupt
    BX      LR

osSchedulerLaunch
    LDR     R0, =tcb_curr   ; R0 = tcb_curr
    LDR     R2, [R0]        ; R2 = *tcb_curr
    LDR     SP, [R2]        ; SP = stakcPt
    POP     {R4-R11}        ; RESET R4 R11
    POP     {R0-R3}         ; Reset R0 R3
    POP     {R12}           ; Reset R12
    ADD     SP, SP, #4      ; SP ++
    POP     {LR}            ; index = 14 STACK_SIZE - 2 = task0
    ADD     SP, SP, #4      ; SP ++
    CPSIE   I               ; enable interrupt
    BX      LR              ; jump lr = jump task0

    ALIGN
    END
