match-making-fun.o: match-making-fun.c match-making-fun.h
	gcc -c match-making-fun.c
match-making.o:match-making.c match-making-fun.h
	gcc -c match-making.c
match-making: match-making.o match-making-fun.o
	gcc *.o -o match-making
all: match-making
	./match-making
