/*
 *this is to understand how to use system() function works ,it takes the input as a string and executes as it is in the command line.
 *this is also about how to use sprintf
 * also just to understand all c functions internally call system calls which is inside the kernel typically or even as a dynamic library .so file
 * by gru the vmeister
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<errno.h>

char* now(void);

 
char* now(void)
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

int main()
{
	char comment[80];
	char info[120];
	
	puts("enter command");
	//getchar();
	//getchar();
	fgets(comment,80,stdin);
	sprintf(info,"echo '%s %s' >>log.txt",comment,now());
	if(system(info) == -1)
		puts(strerror(errno));

	return 0;

}
