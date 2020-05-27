/*
 * this is a program to use rssgossip.py python file using the exec
 * by gru the vmeister
 */

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	  pid_t pid;
	  char *feed[]={"http://feeds.bbci.co.uk/news/world/rss.xml","http://www.cbn.com/cbnnews/world/feed/","https://thewest.com.au/rss-feeds"};
	  int times=3,i;
	  char var[255];

	  for(i=0;i<times;i++)
	  {
		sprintf(var ,"RSS_FEED=%s",feed[i]);
		char *vars[]={var,NULL};
		if((pid=fork())==0)
		{
			if(execle("/usr/bin/python","/usr/bin/python","./rssgossip.py",argv[1],NULL,vars)==-1)
			{
				printf("exec failed :%s",strerror(errno));
				return -1;
			}
		}
		else{

				printf("\nin parent process :%s\nchild process PID :%i\n",strerror(errno),pid);
		}		
	  }
	  printf("\n FIN\n");
	return 0;

}

