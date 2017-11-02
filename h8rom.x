OUTPUT_ARCH(h8300h)
ENTRY("_start")
MEMORY {
        vectors : org =0x000000, len =0x100
        rom     : org =0x000100, len =128k-0x100
        ram     : org =0xffef10, len =4k
        eight   : org =0xffff00, len =0x100
}
SECTIONS {
        .vectors : {
                /* Use something like this to place a specific function's address
                   into the vector table.  */
                /* 0x00 */
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x10 */
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(DEFINED(_int_nmi)?ABSOLUTE(_int_nmi):ABSOLUTE(_start))
                /* 0x20 */
                LONG(DEFINED(_int_trap0)?ABSOLUTE(_int_trap0):ABSOLUTE(_start))
                LONG(DEFINED(_int_trap1)?ABSOLUTE(_int_trap1):ABSOLUTE(_start))
                LONG(DEFINED(_int_trap2)?ABSOLUTE(_int_trap2):ABSOLUTE(_start))
                LONG(DEFINED(_int_trap3)?ABSOLUTE(_int_trap3):ABSOLUTE(_start))
                /* 0x30 */
                LONG(DEFINED(_int_irq0)?ABSOLUTE(_int_irq0):ABSOLUTE(_start))
                LONG(DEFINED(_int_irq1)?ABSOLUTE(_int_irq1):ABSOLUTE(_start))
                LONG(DEFINED(_int_irq2)?ABSOLUTE(_int_irq2):ABSOLUTE(_start))
                LONG(DEFINED(_int_irq3)?ABSOLUTE(_int_irq3):ABSOLUTE(_start))
                /* 0x40 */
                LONG(DEFINED(_int_irq4)?ABSOLUTE(_int_irq4):ABSOLUTE(_start))
                LONG(DEFINED(_int_irq5)?ABSOLUTE(_int_irq5):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x50 */
                LONG(DEFINED(_int_wovi)?ABSOLUTE(_int_wovi):ABSOLUTE(_start))
                LONG(DEFINED(_int_cmi)?ABSOLUTE(_int_cmi):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x60 */
                LONG(DEFINED(_int_imia0)?ABSOLUTE(_int_imia0):ABSOLUTE(_start))
                LONG(DEFINED(_int_imib0)?ABSOLUTE(_int_imib0):ABSOLUTE(_start))
                LONG(DEFINED(_int_ovi0)?ABSOLUTE(_int_ovi0):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x70 */
                LONG(DEFINED(_int_imia1)?ABSOLUTE(_int_imia1):ABSOLUTE(_start))
                LONG(DEFINED(_int_imib1)?ABSOLUTE(_int_imib1):ABSOLUTE(_start))
                LONG(DEFINED(_int_ovi1)?ABSOLUTE(_int_ovi1):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x80 */
                LONG(DEFINED(_int_imia2)?ABSOLUTE(_int_imia2):ABSOLUTE(_start))
                LONG(DEFINED(_int_imib2)?ABSOLUTE(_int_imib2):ABSOLUTE(_start))
                LONG(DEFINED(_int_ovi2)?ABSOLUTE(_int_ovi2):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0x90 */
                LONG(DEFINED(_int_imia3)?ABSOLUTE(_int_imia3):ABSOLUTE(_start))
                LONG(DEFINED(_int_imib3)?ABSOLUTE(_int_imib3):ABSOLUTE(_start))
                LONG(DEFINED(_int_ovi3)?ABSOLUTE(_int_ovi3):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0xA0 */
                LONG(DEFINED(_int_imia4)?ABSOLUTE(_int_imia4):ABSOLUTE(_start))
                LONG(DEFINED(_int_imib4)?ABSOLUTE(_int_imib4):ABSOLUTE(_start))
                LONG(DEFINED(_int_ovi4)?ABSOLUTE(_int_ovi4):ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0xB0 */
                LONG(DEFINED(_int_dend0a)?ABSOLUTE(_int_dend0a):ABSOLUTE(_start))
                LONG(DEFINED(_int_dend0b)?ABSOLUTE(_int_dend0b):ABSOLUTE(_start))
                LONG(DEFINED(_int_dend1a)?ABSOLUTE(_int_dend1a):ABSOLUTE(_start))
                LONG(DEFINED(_int_dend1b)?ABSOLUTE(_int_dend1b):ABSOLUTE(_start))
                /* 0xC0 */
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                LONG(ABSOLUTE(_start))
                /* 0xD0 */
                LONG(DEFINED(_int_eri0)?ABSOLUTE(_int_eri0):ABSOLUTE(_start))
                LONG(DEFINED(_int_rxi0)?ABSOLUTE(_int_rxi0):ABSOLUTE(_start))
                LONG(DEFINED(_int_txi0)?ABSOLUTE(_int_txi0):ABSOLUTE(_start))
                LONG(DEFINED(_int_tei0)?ABSOLUTE(_int_tei0):ABSOLUTE(_start))
                /* 0xE0 */
                LONG(DEFINED(_int_eri1)?ABSOLUTE(_int_eri1):ABSOLUTE(_start))
                LONG(DEFINED(_int_rxi1)?ABSOLUTE(_int_rxi1):ABSOLUTE(_start))
                LONG(DEFINED(_int_txi1)?ABSOLUTE(_int_txi1):ABSOLUTE(_start))
                LONG(DEFINED(_int_tei1)?ABSOLUTE(_int_tei1):ABSOLUTE(_start))
                /* 0xF0 */
                LONG(DEFINED(_int_adi)?ABSOLUTE(_int_adi):ABSOLUTE(_start))

                FILL(0xff)
                }  > vectors
        .text : {
                CREATE_OBJECT_SYMBOLS
                *(.text)
                etext = .;
                } > rom
        .init : {
                *(.init)
                } > rom
        .fini : {
                *(.fini)
                } > rom
        .got : {
                *(.got)
                *(.got.plt)
                } > rom
        .rodata :  {
                *(.rodata)
                *(.rodata.*)
                _erodata = .;
                } > rom
        .eh_frame_hdr : { 
                *(.eh_frame_hdr)
                }> ram
        .eh_frame :  { 
                *(.eh_frame)
                }> rom
        .jcr : { 
                *(.jcr)
                } > rom
        .tors : {
                __CTOR_LIST__ = .; 
                LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2) 
                ___ctors = . ; 
                *(.ctors)
                ___ctors_end = . ; 
                LONG(0) 
                __CTOR_END__ = .; 
                __DTOR_LIST__ = .; 
                LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2) 
                ___dtors = . ; 
                *(.dtors)
                ___dtors_end = . ; 
                LONG(0) 
                __DTOR_END__ = .; 
                _mdata = .; 
                } > rom
        .data : AT (_mdata) { 
                _data = .;
                *(.data)
                *(.data.*)
                _edata = .; 
                } > ram
        .gcc_exc : {
                *(.gcc_exc)
                } > rom
        .bss : {
                _bss = . ;
                *(.bss)
                *(COMMON)
                _ebss = . ;
                _end = . ;
                } > ram
        .stack 0xffff0c : {
                 _stack = . ;
                *(.stack)
                } > ram
        .eight : {
                *(.eight)
                }  > eight
        .stab . (NOLOAD) :  { 
                [ .stab ] 
                } 
        .stabstr . (NOLOAD) : { 
                [ .stabstr ] 
                } 
        /DISCARD/ : {
                *(.comment)
                }
}
