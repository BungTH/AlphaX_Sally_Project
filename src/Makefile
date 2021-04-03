# Makefile for readwrite.c
# of corse in case you are lazy
# just make readwrite and done

EXECUTABLES= readwrite$(EXECEXT)

all : $(EXECUTABLES)

readwrite.o :	readwrite.c datastruct.h
	gcc -c readwrite.c

readwrite$(EXECEXT) : readwrite.o
	gcc -o readwrite$(EXECEXT) readwrite.o


clean : 
	-rm readwrite.o
	-rm readwrite 
