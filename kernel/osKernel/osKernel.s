        AREA| .text|,CODE,READONLY,ALIIGN=2
        THUMB
        EXTERN currentPt
        EXPORT SysTick_Handler
        EXPORT osSchedulerLaunch

SysTick_Handler
    CPSID
    PUSH        {R4-R11}   ; Save r4 from r11
    LDR         R0,=currentPt
    LDR         R1,[R0]
    STR         SP,[R1]
    LDR         R1,[R1,#4]
    STR         R1,[R0]
    LDR         SP,[R1]
    POP         {R4-R11}
    CPSIE       I
    BX          LR

osSchedulerLaunch
    LDR         R0,=currentPt
    LDR         R2,[R0]
    LDR         SP,[R2]
    POP         {R4-R11}
    POP         {R0-R3}
    POP         R12
    ADD         SP,SP,#4
    POP         {LR}
    ADD         SP,SP,#4
    CPSIE       I
    BX          LR

    ALIIGN
    END
