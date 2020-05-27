/*
 * this is to identify the different types mentioned in spooky.csv and segregate them according to their types 
 * learning to create more than the given default datastreams i.e stdin stdout and stderr
 * using File datatype mostly through struct that points to a pointer that has the address of the text files as returned by the fopen function
 * by gru thr vmeister
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char line[80];

	FILE *in = fopen("spooky.csv","r");
	FILE *ufo = fopen("ufo.txt","w");
	FILE *disappearence = fopen("disappearence.txt","w");
	FILE *others = fopen("others.txt","w");

	while(scanf("%79[^\n]\n",line)==1)
	{
		if(strstr(line,"UFO"))
		{
			fprintf(ufo,"%s\n",line);
		}
		else if(strstr(line,"Dis"))
		{
			fprintf(disappearence,"%s\n",line);
		}
		else 
		{
			fprintf(others,"%s\n",line);
		}
			
	}
	fclose(ufo);
	fclose(disappearence);
	fclose(others);

	return 0;
}
