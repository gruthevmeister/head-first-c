
#include "linked-list-fun.h"

void display(island* start)
{
	island *i=start;
	for(;i!=NULL;i=i->next)
	{
		printf("\nname:%s\n open: %s-%s\n",i->name,i->opens,i->closes);
	}
}

island* create(char* n)
{
	island *i=malloc(sizeof(island));

	i->name=strdup(n);
	i->opens="7:00 a.m";
	i->closes="10:00 p.m";
	i->next=NULL;
       
	return i;
}

void release(island* i)
{
	island* j=i;
	island* next=NULL;
	for(;j!=NULL;j=next)
	{
		next=j->next;
		free(j->name);
		free(j);
	}
}
