fish-details-fun.o:fish-details-fun.c fish-details-fun.h
	gcc -c fish-details-fun.c
fish-catalog.o:fish-catalog.c fish-details-fun.h
	gcc -c fish-catalog.c
fish-catalog:fish-catalog.o fish-details-fun.o
	gcc *.o -o fish-catalog 
all:fish-catalog
	./fish-catalog


