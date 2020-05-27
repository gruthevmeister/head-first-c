/*
 * this chapter is to learn to create tools for eg: tools like ls ans clear used in terminal
 * so as to learn this the chapter starts with a task to convert a comma seperated data into json format
 * by gru the Vmeister
 */

#include <stdio.h>

int main()
{
	float latitude,longitude;
	char info[30];
	int data=0;

	puts("data=[");



 	while(scanf("%f,%f,%29[^\n]",&latitude,&longitude,info))
	{
		if(latitude>90 | latitude<-90)
		{
			fprintf(stderr,"invalid latitude");
			return 2;
		}

		if(latitude>90 | latitude<-90)
		{

			fprintf(stderr,"invalid longitude");
			return 2;
		}
		printf("{latitude:%f, longitude:%f, info: '%s'},\n",latitude,longitude,info);

	}
	puts("\n]");

	return 0;
}
