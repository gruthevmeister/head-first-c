#include "encrypt.h"
#include <stdlib.h>


int code_num=31;
void encrypt(char* t)
{
	char *temp=t;
//	printf("%s\n",t);

	while(*t)
	{
        
//	printf("%c\n",*t);
//	     
		*t = (*t) ^ code_num;
	//	printf("%c",*t);
		t++;
	}
	printf("\n%s\n",temp);

}
