/*
 * this is to identify the different types mentioned in spooky.csv and segregate them according to their types 
 * learning to create more than the given default datastreams i.e stdin stdout and stderr
 * using File datatype mostly through struct that points to a pointer that has the address of the text files as returned by the fopen function
 * by gru thr vmeister
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char line[80];

	if(argc!=6)
	{
		fprintf(stderr,"\nError :the number of parameters is wrong\n"); 
		return 2;
	}

	FILE *in = fopen("spooky.csv","r");

	FILE *file1 = fopen(argv[2],"w");
	FILE *file2 = fopen(argv[4],"w");
	FILE *file3 = fopen(argv[5],"w");

	while(fscanf(in,"%79[^\n]\n",line)==1)
	{
	//	puts("in loop");
		if(strstr(line,argv[1]))
		{
			fprintf(file1,"%s\n",line);
		}
		else if(strstr(line,argv[3]))
		{
			fprintf(file2,"%s\n",line);
		}
		else 
		{
			fprintf(file3,"%s\n",line);
		}
			
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);

	return 0;
}
