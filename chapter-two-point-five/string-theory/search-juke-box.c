/*
 * this program is to find a song in the list of songs provided using strstr in string.h
 * strstr finds the location of the string in the list of songs and returns the value 
 * we have to use fgets to get the name of the song the user wants to search since scanf cannot be used to get a sentence with spaces unless it is structured
 * by Gru the Vmeister
 * on  at 19:02
 */

#include <stdio.h>
#include <string.h>


void search_for(char *s);

 char track[][80]={"I left my heart in Harvard Med School",
	 	   "Newark, Newark - a wonderful town",
		   "Dancing with a Dork",
		   "From here to Maternity",
		   "The girl from Iwo Jima"
	           };

int main()
{
	char search[80];
	puts("search for:");
	//fgets(search,80,stdin);
	scanf("%s",search);
	printf("\nsearched for : %s\n",search);
	search_for(search);
	
	return 0;
}


void search_for(char *s)
{
	int i;


//	printf("\nsearched for : %s \n",track[0]);
	for(i=0;i<5;i++)
	{
		if( strstr(track[i],s) )
		{
			printf("\n track[%d] :%s \n",i,s);
		}
//		printf("\ntest[%d]\n",i);

		
	}

}
