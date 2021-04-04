# Makefile for readwrite.c
# of corse in case you are lazy
# just make readwrite and done

EXECUTABLES= readwrite$(EXECEXT)

all : $(EXECUTABLES)


dtype.o : dtype.c dtype.h datastruct.h
	gcc -c dtype.c

readwrite.o : readwrite.c datastruct.h dtype.h
	gcc -c readwrite.c

readwrite$(EXECEXT) : readwrite.o dtype.o
	gcc -o readwrite$(EXECEXT) readwrite.o dtype.o


clean : 
	-rm *.o
	-rm readwrite 