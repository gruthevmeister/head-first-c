/*
 * this is to understand how to use alarm() to generate sigalrm signal 
 * also using kill from another terminal i can generate another signal but always a kill -KILL will kill a signal
 * alarm and sleep() cannot be used in the same process coz it both uses the same interval timer
 * also a process is limited to one timer 
 * alarm resets itself every time its called so set an alarm for 10 sec and them set it for 10 min it will only fire after 10 mins
 * by gru the vmeister
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>
#include<signal.h>

int noq=0;
int total=0;

void error(char* msg)
{
	printf("%s %s\n",msg,strerror(errno));
	exit(-1);
}

int catch_signal(int sig,void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler=handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags=0;

	return sigaction(sig,&action,NULL);

}

void end_of_quiz(int i)
{
	printf("\ntotal quesions %d \ntotal score=%d \n",noq,total);

	printf("\nCongrats \nyou have become another brick in the wall\n");
	exit(1);
}

void time_up(int i)
{
	puts("\noops....times up\n better luck next time\n");
	//printf("your score is %d\n",i);
	raise(SIGINT);
}


int main()
{
	int i=0,ans=0;
	catch_signal(SIGINT,end_of_quiz);
	catch_signal(SIGALRM,time_up);
	
	while(1)
	{
		printf("\n2 * %i = ?",i);
		alarm(8);
		scanf("%i",&ans);
		if((2*i)==ans)
		{
			total++;
		}
		else
		{
			puts("wrong!!");
		}
		i++;
		noq++;
	}


	return 0; 	
}
