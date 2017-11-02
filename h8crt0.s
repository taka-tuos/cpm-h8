        .h8300h
        .section .text
        .global _start
        .global _exit

        .extern _main
        .extern _data
        .extern _mdata
        .extern _edata
        .extern _bss
        .extern _ebss
        .extern _stack

_start:
        mov.l   #_stack,sp

        ;; copy DATA from ROM
        mov.l   #_mdata,er0
        mov.l   #_data,er1
        mov.l   #_edata,er2
data_init_loop:
        cmp     er2,er1
        bge     fin_data_init
        mov.b   @er0+,r3l
        mov.b   r3l,@er1
        adds    #1,er1
        bra     data_init_loop
fin_data_init:

        ;; clear BSS
        mov.l   #_bss,er0
        mov.l   #_ebss,er1
        mov.b   #0,r2l
bss_init_loop:
        cmp     er1,er0
        bge     fin_bss_init
        mov.b   r2l,@er0
        adds    #1,er0
        bra     bss_init_loop
fin_bss_init:

        jsr     @_main

_exit:
        sleep
        bra     _exit
