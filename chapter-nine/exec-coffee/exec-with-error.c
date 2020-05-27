/*
 * this is to use exec and replace the current process with the new one mentioned in the exec command
 * exec can be used in multiple ways execl is list of arguments and execv is array of arguments .l or v followed by p or e . p - path  and e - environment variable 
 * so follows an example
 * by gru the vmeister
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>


int main(int argc, char* argv[])
{
	char* env_string[]={"FOOD=donut",NULL};
	
//	puts(env_string[0]);	

	execle("./coffee","./coffee","cofee",NULL,env_string);
	
	puts(strerror(errno));
	return -1;
}
