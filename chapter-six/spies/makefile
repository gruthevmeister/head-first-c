spies-fun.o:spies-fun.c spies-fun.h 
	gcc -c spies-fun.c

spies.o:spies.c spies-fun.h
	gcc -c spies.c

spies:spies.o spies-fun.o
	gcc -g *.o -o spies

all:spies
	./spies

