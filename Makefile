TARGET	= cpm-h8
OBJ		= main.o xprintf.o sci1.o mmc_bb.o z80cpm.o z80emu.o h8crt0.o

PREFIX	= h8300-elf-

CFLAGS	:= -Os -mh -mint32 -nostartfiles -std=gnu99 -Wall 
ASFLAGS	:= 
LDFLAGS	:= $(CFLAGS) -Wl,-Map=$(TARGET).map -T h8rom.x
LIBS	:= 

include Makefile.in
