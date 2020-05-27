/*
 * this is to understand blab
 * for a client to connect to a server .it needs to know ip address and port number 
 * eg: telnet 127.0.0.1 3000
 * where 127.0.0.1 can be used if the client and server is on the same machine
 * 3000 is the port number
 * BLAB bind to a port ,listen ,Accept a client,begin talking
 * begin is not the name of the function unlike others in BLAB it is send instead.
 * by gru the vmeister
 */

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void error(char*msg)
{
	printf("\n%s : %s\n",msg,strerror(errno) );
	exit(-1);
}

int read_in(int socket,char* buff,int len)
{
	char* s=buff;
	int slen=len;
	int c=recv(socket,s,slen,0);
	while((c>0)&&(s[c-1]!='\n'))
	{
		s+=c;
		slen-=c;
		c=recv(socket,s,slen,0);		
	}
	if(c<0)
	 error("recv error");
	else if(c==0)
	{
		buff[c-1]='\0';	
	}
	else
	{
		s[c-1]='\0';
	}
	return len-slen;
		
}



int main(int argc, char *argv[])
{
	char* buf;
	char *advice[] = {
	"Take smaller bites\r\n",
	"Go for the tight jeans. No they do NOT make you look fat.\r\n",
	"One word: inappropriate\r\n",
	"Just for today, be honest. Tell your boss what you *really* think\r\n",
	"You might want to rethink that haircut\r\n"
	};

	int reuse =1;
	int listener_d =socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in name;

	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);


	if(setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
	error("Can't set the reuse option on the socket");
	
	if(bind(listener_d, (struct sockaddr *) &name, sizeof(name))==-1)
	{
		error("cant bind");		
	}

	if(listen(listener_d, 10)==-1)
	{
		error("cant listen");
	}
	puts("Waiting for connection");

	struct sockaddr_storage client_addr;

	unsigned int address_size = sizeof(client_addr);

	int connect_d =accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
	if(connect_d==-1)
	{
		error("cant accept");
	}

	char *msg = advice[rand() % 5];
	if(send(connect_d, msg, strlen(msg), 0)==-1)
		error("cant send");

	if(send(connect_d,“Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n>“,80) != -1) 
	{
		read_in(connect_d, buf, 15);
		if (strncasecmp(“Who’s there?”, buf, 12))
		{
		send(connect_d, “You should say ‘Who’s there?’!”,40);
		}
		else
	       	{
			if (send(connect_d, “Oscar\r\n> “,15) != -1) 
			{
				read_in(connect_d, buf, 15);
				if (strncasecmp(“Oscar who?”, buf, 10))
				send(connect_d, “You should say ‘Oscar who?’!\r\n”,50);
				else
				send(connect_d, “Oscar silly question, you get a silly answer\r\n”,50);
			}
		}
	}
			

	close(connect_d);
	return 0;
}
