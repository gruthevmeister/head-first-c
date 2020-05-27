display-function.o:display-function.c display-function.h
	gcc -c display-function.c 

mix.o:mix.c display-function.h
	gcc -c mix.c 

mix:mix.o display-function.o
	gcc *.o -o mix
all: mix
	./mix
