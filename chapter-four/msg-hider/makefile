encrypt.o:encrypt.c encrypt.h
	gcc -c encrypt.c

msg-hider.o:encrypt.h msg-hider.c
	gcc -c msg-hider.c 

msg-hider: encrypt.o msg-hider.o
	gcc *.o -o msg-hider
