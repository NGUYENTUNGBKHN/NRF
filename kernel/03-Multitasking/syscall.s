.thumb
.syntax unified
.arch   armv7e-m


.globl syscall
syscall:
    svc 0
    nop
    bx  lr
