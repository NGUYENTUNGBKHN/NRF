        AREA | .text|, CODE, READONLY, ALIGN=2
        THUMB
        EXTERN currentPt
        EXPORT SysTick_Handler
        EXPORT osSchedulerLaunch

SysTick_Handler
    CPSID		I               ; interrupt disable
    PUSH        {R4-R11}        ; Save r4 from r11
    LDR         R0,=currentPt   ; R2 = current    
    LDR         R1,[R0]         ;   R1 = *current
    STR         SP,[R1]         ; current->stackPt1 = SP
    LDR         R1,[R1,#4]      ; R1 = current->nextPt
    STR         R1,[R0]         ; current = current->nextPt 
    LDR         SP,[R1]         ; SP = current->nextPt
    POP         {R4-R11}        ; get R4 R11
    CPSIE       I               ; interrupt enable
    BX          LR              ; return LR

osSchedulerLaunch
    LDR         R0,=currentPt   ; R0 = current
    LDR         R2,[R0]         ; R2 = *currrent
    LDR         SP,[R2]         ; SP = current->stackPt
    POP         {R4-R11}        ; clear R4 to R11
    POP         {R0-R3}         ; clear R0 to R3
    POP         {R12}           ; clear R12
    ADD         SP,SP,#4        ; why add sp ? skip SP register in stack
    POP         {LR}            ; get LR in stack to LR register of processor
    ADD         SP,SP,#4        ; skip PC
    CPSIE       I               ; enable interrupt
    BX          LR              ;  return LR return task0

    ALIGN
    END
