/*
 * to understand qsort in detail
 * address of the functions that is function name lives in constant part of the memory of the process
 * by gru the vmeister
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascend_sort(const void*,const void*);

int compare_names(const void* a,const void* b);

int ascend_sort(const void* score_a,const void* score_b)
{
	int a=*((int*)score_a);
	int b=*((int*)score_b);
	return b-a;
}

int compare_names(const void* a,const void* b)
{
	char** sa=(char**)a;
	char** sb=(char**)b;
	
	return strcmp(*sa,*sb);
}

int main()
{
	int i;
	int scores[] = {543,323,32,554,11,3,112};
	
	qsort(scores,7,sizeof(int),ascend_sort);
	
	for(i=0;i<7;i++)
	printf("%d,",scores[i]);
	puts("");
	
	char *names[] = {"Karen", "Mark", "Brett", "Molly"};

	
	qsort(names,4,sizeof(char*),compare_names);

	for(i=0;i<4;i++)
	printf("%s,",names[i]);
	puts("");

}
