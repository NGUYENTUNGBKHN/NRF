        AREA | .text|, CODE, READONLY, ALIGN=2
        THUMB
        EXTERN tcb_current
        export SysTick_Handler
        export osSchedulerLaunch

SysTick_Handler
    CPSID       I                       ; interrupt disable
    PUSH        {R4-R11}                ; Save R4 - R11
    LDR         R0,=tcb_current         ; R0 = currernt
    LDR         R1,[R0]                 ; R1 = *current
    STR         SP,[R1]                 ; current->stackPt = SP
    LDR         R1,[R1,#4]              ; R1 = current->nextPt
    STR         R1,[R0]                 ; current = current->nextPt
    LDR         SP,[R1]                 ; SP = current->nextPt
    POP         {R4-R11}
    CPSIE       I
    BX          LR


osSchedulerLaunch
    LDR         R0,=tcb_current         ; assign address of tcb_current to R0
    LDR         R2,[R0]                 ; R2 = *currrent
    LDR         SP,[R2]                 ; SP = currrent->stackPt
    POP         {R4-R11}
    POP         {R0-R3}
    POP         {R12}
    ADD         SP,SP,#4
    POP         {LR}
    ADD         SP,SP,#4
    CPSIE       I
    BX          LR

    ALIGN
    END


