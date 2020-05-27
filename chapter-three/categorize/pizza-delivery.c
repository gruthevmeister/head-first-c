/*
 * this is a program to learn command line options using getopt() function it returns a character
 * it has extra parameters that stores the value of the argument called optarg 
 * optind is the count value of the number of time the getopt() was called
 * by gru the vmeister
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	char ch;
//	char *name[]="";
	char *when;
	int delivery=0,thick=0,i=0;

	while((ch=getopt(argc,argv,"d:t")) !=EOF)
	{
		switch(ch)
		{
			case 'd': 
				  delivery=1;
				  when = optarg;
				  break;
		 	case 't':
				  thick=1;
				  break;
		 	default:
				  fprintf(stderr,"\nunknown option\n");
				  return 1;
		}
	}

	argc -=optind;
	argv +=optind;

	if(delivery==1)
	{
		printf("\n To be delivered %s\n",when);
	}
	if(thick==1)
	{
		puts("thick crust");
		puts("ingredients:");
	}

	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}

	return 0;
}
