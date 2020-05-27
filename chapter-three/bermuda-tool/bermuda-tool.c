/*
 * this is a small tool to identify a particular range of longitude and latitude 
 * and then send the output to geo-to-json tool
 * by gru the vmeister
 * on 30-3-20 at 10:45 am
 */

#include <stdio.h>

int main()
{
	float lat;
	float lon;
	char info[30];

	while(scanf("%f,%f,%29[^\n]",&lat,&lon,info)==3)
	{
		if(lat>26 & lat<34)
		{
			if(lon>-76 && lon<-64)
			{
				fprintf(stdout,"%f,%f,%29s\n",lat,lon,info);
			}
		}
		else
		{
			//this is to indicate out of range can be put in another file
			fprintf(stderr,"%f,%f,%29s\n",lat,lon,info);
		}

	}
	puts("...");

	return 0;
}
