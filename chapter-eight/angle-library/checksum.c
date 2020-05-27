/*
 */

#include<stdio.h>

extern int code_num;

int checksum(char* c)
{
		char* temp_c=c;
		int checksum=0;

		while(*temp_c)
		{
			checksum^=(int)(*temp_c);
			temp_c++;
		}
		return checksum;

}
