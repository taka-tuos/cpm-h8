TARGET	= h8test
OBJ		= main.o xprintf.o h8crt0.o

PREFIX	= h8300-elf-

CFLAGS	:= -mh -mint32 -nostartfiles -std=gnu99 -Wall 
ASFLAGS	:= 
LDFLAGS	:= -mh -mint32 -nostartfiles -T h8rom.x
LIBS	:= 

include Makefile.in
