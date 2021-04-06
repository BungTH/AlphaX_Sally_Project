######################################
#
#
#	Makefile AlphaX
#
#
#
######################################

EXECUTABLES= photoengine

all : $(EXECUTABLES)

dtype.o : dtype.c dtype.h datastruct.h
	gcc -c dtype.c

readwrite.o : readwrite.c readwrite.h dtype.h datastruct.h
	gcc -c readwrite.c
	
model.o : model.c dtype.h datastruct.h
	gcc -c model.c
	
controller.o : controller.c dtype.h readwrite.h model.h datastruct.h
	gcc -c controller.c
	
photoengine : controller.o model.o readwrite.o dtype.o dtype.h readwrite.h model.h datastruct.h
	gcc -o photoengine controller.o model.o readwrite.o dtype.o

clean : 
	-rm *.o
	-rm photoengine
