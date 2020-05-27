linked-list-fun.o:linked-list-fun.c linked-list-fun.h
	gcc -c linked-list-fun.c
island-heap.o:island-heap.c linked-list-fun.h
	gcc -c island-heap.c
island-heap:linked-list-fun.o island-heap.o
	gcc *.o -o island-heap
all:island-heap
	./island-heap
