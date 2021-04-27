#######################################
#
#	Makefile AlphaX photo search engine
#
#######################################

EXECUTABLES= photoengine

all : $(EXECUTABLES)

dtype.o : dtype.c dtype.h datastruct.h
	gcc -c dtype.c

readwrite.o : readwrite.c readwrite.h dtype.h datastruct.h
	gcc -c readwrite.c
	
model.o : model.c dtype.h model.h datastruct.h
	gcc -c model.c
	
controller.o : controller.c controller.h dtype.h readwrite.h model.h datastruct.h
	gcc -c controller.c

view.o : view.c view.h getinput.h datastruct.h
	gcc -c view.c

getinput.o : getinput.c model.h getinput.h datastruct.h	
	gcc -c getinput.c

photoengine : controller.o model.o readwrite.o dtype.o getinput.o view.o getinput.o 
	gcc -o photoengine controller.o model.o readwrite.o dtype.o view.o getinput.o  

clean : 
	-rm *.o
	-rm photoengine
