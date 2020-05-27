/*
 * this is to use pipes and initiate a conversation with parent and child
 * this is to also acquire links through rssgossip.py using -u switch and grep it with grep 'http' to obtain the links 
 * by gru the vmeister
 */

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

void error(char* msg);
void open_url(char*);

void open_url(char* url)
{
	char *launch;
	sprintf(launch,"firefox %s &",url);
	system(launch);
}

void error(char* msg)
{
	printf("%s \n %s \n",msg,strerror(errno));
	exit(1);
}

int main(int argc,char* argv[])
{
	char* link[]={"RSS_FEED=http://feeds.bbci.co.uk/news/world/rss.xml",NULL};

	char* phrase=argv[1];
	int pid;
	int f[2];

	if(pipe(f)==-1)
	{
		error("pipe Error:"); 
	}


	pid=fork();

	if(pid==-1)
	{
		error("cant fork:");
	}
	if(!pid)
	{
		close(f[0]);
		dup2(f[1],1);

		if(execle("/usr/bin/python","usr/bin/python","rssgossip.py","-u",phrase,NULL,link)==-1)
		{
			error("exec error:");
		}

	}
	else if(pid)
	{
		close(f[1]);
		dup2(f[0],0);
		char line[255];
		while(fgets(line,255,stdin))
		{
			if(line[0]=='\t') 
				open_url(line+1);
		}


	}
	return 0;
}
