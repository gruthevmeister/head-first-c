/*
 * this is to understand sharing c source codes especially if you want to share functions 
 * before that a quick revision of the cool things i learnt main(argc,argv[]) so that command line arguments can be set using get opt to use command options to create new files using fopen it was epic i would only like to learn and use it more often so i dont forget it to create streams is to open files and use them 
 * by gru the vmeister
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "encrypt.h"

int main(int argc,char *argv[])
{
	short i;
	char sh;
	extern int code_num;
	char *msg[10];
	
	while((sh=getopt(argc,argv,"n:")) != EOF)
	{
		switch(sh)
		{
			case 'n':
				code_num=atoi(optarg);	
				
			//	printf("\ncode num=%d",code_num);

				break;
			default:
			 	puts("Error: wrong option ");
				return 1;
		}

	}
	argc -=optind;
	argv +=optind;

	FILE *output;
	if(!(output=fopen("output.txt","a")))
	{
		puts("Error: opening file");
		return 1;
	}
	for(i=0;i<argc;i++)
	{
	//	puts("test");
		//scanf("%s",argv[i]);
		encrypt(argv[i]);
	}
	fclose(output);

	for(i=0;i<100;i++)
	{}

	return 0;
}
