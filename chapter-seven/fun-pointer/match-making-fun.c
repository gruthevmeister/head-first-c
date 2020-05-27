#include "match-making-fun.h"


char *ads[] = {"William: SBM GSOH likes sports, TV, dining","Matt: SWM NS likes art, movies, theater","Luis: SLM ND likes books, theater, art","Mike: DWM DS likes trucks, sports and bieber","Peter: SAM likes chess, working out and art","Josh: SJM likes sports, movies and theater","Jed: DBM likes theater, books and dining"};

int sports_no_bieber(char *s)
{
	return strstr(s,"sports") && !strstr(s,"bieber");
}	

int sports_or_workout(char *s)
{
	return strstr(s,"sports") || strstr(s,"workout");
}	

int ns_theatre(char *s)
{
	return strstr(s,"NS") || strstr(s,"theatre");
}

int arts_theatre_or_dining(char *s)
{
	return (strstr(s,"arts") || strstr(s,"theatre") )|| strstr(s,"dining");
}


void find (int (*find_pointer) (char*))
{
	int i;
	
	for(i=0;i<7;i++)
	{
		if(find_pointer(ads[i]))
		{
			printf("\nMatch Found :%s\n",ads[i]);
		}
	}
	puts("----------------------------------------");

}       
