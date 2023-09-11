        AREA | .text|, CODE, READONLY, ALIGN=2
        THUMB
        EXTERN tcb_current
        export Systick_handler
        export osSchedulerLaunch

Systick_handler:




osSchedulerLaunch:
    LDR     R0,=tcb_current     ; assign address of tcb_current to R0
    

