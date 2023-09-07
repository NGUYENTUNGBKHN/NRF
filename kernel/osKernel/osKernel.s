        AREA| .text|,CODE,READONLY,ALIIGN=2
        THUMB
        EXTERN currentPt

SysTick_Handler
    CPSID
    PUSH        {R4-R11}   ; Save r4 from r11
    LDR         R0,=currentPt
    LDR         R1,[R0]
    STR         SP,[R1]
    LDR         R1,[R1,#4]
    STR         R1,[R0]
    LDR         SP,[R1]

