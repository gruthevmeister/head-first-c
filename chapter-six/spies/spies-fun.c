#include "spies-fun.h"

node* create(char* q)
{
	node* temp= malloc(sizeof(node));
	char* ques=strdup(q);
	temp->quest=ques;
	temp->yes=NULL;
	temp->no=NULL;

	return temp;
}


void display(node* current)
{
	printf("\n%s ",current->quest);
}

int yes_no(char* a)
{
	if(a[0]=='y')
		return 1;
	else
		return 0;
}


void release(node* start)
{
	int count=0;
	node *i=start;
	node *previous_node = NULL;

	while(start->yes !=NULL)
	{
		previous_node=i;
		i=i->yes;
		if(i->no !=NULL)
		{
			free(i->no->quest);
			free(i->no);
		}
		if(i->yes->yes ==NULL)
		{
			free(i->no->quest);
			free(i->no);
			free(i->yes->quest);
			free(i->yes);
			free(i);
			i=previous_node;
			free(i);

			i=start;
			//count=0;
		}
		
	}

	while(start->no !=NULL)
	{
		previous_node=i;
		if(count==0)
		{
			count++;
			i=i->no;
		}
		else{
			i=i->yes;
		}
		if(i->no !=NULL)
		{
			free(i->no->quest);
			free(i->no);
		}
		if(i->yes->yes ==NULL)
		{
			//free(i->no->quest);
			//free(i->no);
			free(i->yes->quest);
			free(i->yes);
			free(i);

			i=previous_node;
			free(i);

			i=start;
			count=0;
		}
		
	}

	free(start);

	
}
