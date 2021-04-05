# Makefile for readwrite.c
# of corse in case you are lazy
# just make readwrite and done

EXECUTABLES= readwrite$(EXECEXT)

all : $(EXECUTABLES)


dtype.o : dtype.c dtype.h datastruct.h
	gcc -c dtype.c

readwrite.o : readwrite.c readwrite.h dtype.h datastruct.h
	gcc -c readwrite.c
	
model.o : model.c dtype.h datastruct.h
	gcc -c model.c


clean : 
	-rm *.o
	-rm readwrite
