/*
 * this is to understand how to use signals like ctrl+c this is just a interrupt signal thats triggered by the os when the keys are pressed
 * this is similar to the file descriptor table that was mentioned in the earlier chapter
 * it has a table of its own too where sigint is represented by 2
 * this is to write a handler and point it to the signal so that the custom handler function will get executed when the signal is triggered
 * by gru the vmeister
 */

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<signal.h>

void error(char*);
int catch_signal(int sig,void (*handler)(int));

void diediedie(int);

void diediedie(int p)
{
	printf("\n Goodbye cruel world\n");
	exit(-1);
}

void error(char*msg)
{
	fprintf(stderr,"%s \n%s\n",msg,strerror(errno));
	exit(1);
}


int catch_signal(int sig,void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler=handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags=0;

	return sigaction(sig,&action,NULL);
}

int main()
{
	char name[30];
	 if(catch_signal(2,diediedie)==-1)
		 error("signal error:");
	 puts("\n Enter something irrelevent coz i dont care \n");
	 fgets(name,30,stdin);
	 printf("you are wasted");

	 return 0;
}
