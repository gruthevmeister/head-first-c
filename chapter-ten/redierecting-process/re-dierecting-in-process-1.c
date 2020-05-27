
/*
 * this is to redierect data streams in a process apparently when a process is created the info of its datastream is also stored in the memory allocated to it . this is called a file descriptor .
 * file descriptor is just a number to which file pointers are allocated
 * by default the file descriptor 0 - is stdin 1- stdout 2- stderr
 * the fileno(FILE*) would give you an integer value that represents the number in the table 
 * and dup2(4,3) means whatever pointer was in 4 will be copied into 3 .
 * by gru the vmeister4
 */

#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

void error(char*);

void error(char* msg)
{
	printf("\n%s : %s\n",msg,strerror(errno));
	exit(1);
}


int main(int argc,char* argv[])
{
	pid_t pid;

	int num,pid_status;
	FILE* f;
	char* phrase=argv[1];
	char* var[]={"RSS_FEED=http://feeds.bbci.co.uk/news/world/rss.xml",NULL};
	
 	f=fopen("stories.txt","w");
	if(f==0)
	error("Error opening file");

	if(!(pid=fork()))
	{
		printf("in child process");

			printf("\n pid: %d\n",pid); 
		        num=fileno(f);
			printf("\nnum=%d\n",num);
			if(dup2(num,1)==-1)
			{
				error("can't redierect file");
			}


		if(execle("/usr/bin/python","/usr/bin/python","./rssgossip.py",phrase,NULL,var)==-1)
		{
			error("exec error:");		
				
		}
		else
		{
			puts(strerror(errno));
		}	
		
	}
	else if(pid==-1)
	{                  
		error("can't fork:");
	}

	if(waitpid(pid,&pid_status,0)==-1)
	{
		error("error waiting for child process:");
	}
	if(WEXITSTATUS(pid_status))
	{
		error("non zero exit status");
	}	
      return 0;
}
