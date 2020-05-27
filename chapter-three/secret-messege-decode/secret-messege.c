/*
 * this is a program to interpret a secret code messege
 * but mostly to revise the concepts of redierection
 * by gru the vmeister
 */

#include <stdio.h>

int main()
{
	char msg[10];
	int i=0;

	while(scanf("%9s",msg)==1)
	{
		i++;
		if(i%2)
		{
			fprintf(stdout,"%s",msg);
		}
		else
		{
			fprintf(stderr,"%s",msg);
		}

		puts("\n");
	}

	return 0;
}
