/*
 * this  is a program to understand how programs talk to each other using networks so as to do that there are two programs needed a server and a client
 * the client program that we are about to use is called telnet
 * it requires ip address and the port as input
 * if the program needs to talk to the other programs over the network unlike the other data stream we require a different data stream called the sockets
 * sockets can be created using the socket() in sys/socket.h it will return an integer value that which is called the socket descriptor.
 * before the converstion can be started by the server it has through go through BLAB (bind the port,listen,accept the connection,Begin talking)
 * an os might have to talk to different client at once so as to not get the conversation crossed we have to have different ports for different server services
 * a server should say the os which port it is going to use this is called binding the port
 * to bind the port we need socket descriptor and socket name so as to do that we use #include <arpa/inet.h>
 * then once binded we then listen using listen() this is to tell the os how long the queue will be ,meaning to tell how many clients can access it at once if more clients try to access it then the os will say the server is busy.
 * then we accept a connection using accept function call . this will return a secondary socket that will be used to BEgin talking.
 * socket is not the typical data type it is different and so as to talk using this datastram we have to use two func send() and recv().
 * by gru the vmeister
 */

#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include <arpa/inet.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


int listener_d;

void error(char *msg)
{
	printf("\n %s : %s\n",msg,strerror(errno));
	exit(-1);
}

void bye(int sig)
{
	if(listener_d)
		close(listener_d);

	puts("bye");
	exit(0);
}

int catch_signal(int sig, void (*handler)(int))
{
struct sigaction action;
action.sa_handler = handler;
sigemptyset(&action.sa_mask);
action.sa_flags = 0;
return sigaction (sig, &action, NULL);
}

int read_in(int sock,char* buff,int len)
{
	char* s=buff;
	int slen=len;
	int c;
	c= recv(sock,s,len,0);
	while(c>0 && s[c-1]!='\n')
	{
		puts("in while loop to call recv again");
		s+=c;
		slen=slen-c;
		recv(sock,s,slen,0);
	}
	if(c<0)
	{
		error("error recv");
	}
	else if(c==0)
	{
		puts("client closed connection");
	}else
	{
		return slen -len;
	}

}



int main(int argc,char* argv[])
{

	char recieve_buff[100];
	if(catch_signal(SIGINT,bye))
		error("sigint error");


	listener_d = socket(PF_INET, SOCK_STREAM, 0);
	if (listener_d == -1)
	error("Can't open socket");

	int reuse=1;
	if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
	error("Can't set the reuse option on the socket");

	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
	if(c==-1)
		error("cant bind port");
	
	if (listen(listener_d, 10) == -1)
	error("Can't listen");


	puts("waiting for connection");

	while(1)
	{
	struct sockaddr_storage client_addr;	
	unsigned int address_size = sizeof(client_addr);
	int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
	if (connect_d == -1)
	error("Can't open secondary socket");

	if(!fork())
	{
		close(listener_d);

	char *msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ";
	if (send(connect_d, msg, strlen(msg), 0) == -1)
	error("send error");

	if(!(read_in(connect_d,recieve_buff,14)))
	{
		if(strstr(recieve_buff,"who's there?"))
		{
			puts("trial success");
			if(send(connect_d,"Oscar",6,0)==-1)
				fprintf(stderr,"send error");
			
			if(!(read_in(connect_d,recieve_buff,12)))
				if(strstr(recieve_buff,"oscar who?"))
					if(send(connect_d,"oscar silly question,you get a silly answer",46,0)==-1)
						fprintf(stderr,"send error");
		}
		else
		{
		if(send(connect_d,"you should say oscar who..",28,0)==-1)
				fprintf(stderr,"send error");
		raise(SIGINT);
		}
	}
	close(connect_d);
	exit(0);
	}
	close(connect_d);			
	}

	return 0;

}
