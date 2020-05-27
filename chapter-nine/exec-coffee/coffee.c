
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	char* w=getenv("FOOD");
	
	if(!w)
	{
	//	puts("w test in extras");
		w=getenv("EXTRAS");
	}
	if(!w)
	{

	//	puts("w test in argv");
		w=argv[argc-1];
	}
	char* c=getenv("EXTRAS");
	if(!c)
	{
//		puts("c test in argv");
		c=argv[argc-1];
	}

	printf("%s with %s",c,w);

	return 0;
}
