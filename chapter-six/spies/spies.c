/*
 * this is trees in datastructure 
 * by gru the vmeister
 */

#include <stdio.h>
#include "spies-fun.h"

int main()
{
	char ans[3];
	char n[20];
	char q[70];
	char* start_q="has a moustache";
	node* current_node=NULL;
	node* node_to_merge=NULL;
	node* temp_node=NULL;
	node *first_node=create(start_q);
	first_node->yes=create("vinny the spoon");
	first_node->no=create("larns barnsworth");
	
//	printf("\n%s\n%s\n%s\n",first_node->quest,first_node->yes->quest,first_node->no->quest);

	while(1)
	{
	
		current_node=first_node;
	while(1)
	{

		printf("\nDoes suspect %s?\n",current_node->quest);
		scanf("%s",ans);

		if(yes_no(ans))
		{
			if((current_node->yes->yes) !=NULL)// || (current_node->yes->no)) != NULL)
			{
				puts("in here");
				current_node=current_node->yes;
				continue;
			}

			printf("\n%s? (y/n)\n",current_node->yes->quest);
			scanf("%s",ans);
			if(yes_no(ans))
			{
			 puts("Suspect Identified \nrun again (y/n):");
			 scanf("%s",ans);

			 	if(yes_no(ans))
			 	{
					break;
			 	}			 
			 	else
			 	{
					 return 0;
			 	}
			 
			}
			else
			{
					
				puts("who's the suspect?");
			 	getchar();
				fgets(n,20,stdin);
				printf("give me a question that is TRUE for %s but for %s\n",n,current_node->yes->quest);
				fgets(q,70,stdin);
				
				node_to_merge =create(q);
				node_to_merge->yes= create(n);
				
				temp_node=current_node->yes;

				current_node->yes=node_to_merge;
				node_to_merge->no= temp_node;
				


//				printf("no =%s\nyes=%s\nq=%ss",node_to_merge->no->quest,node_to_merge->yes->quest,node_to_merge->quest);

				puts("Run again (y/n)");
				scanf("%s",ans);

				if(yes_no(ans))
				{
					break;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{

			if((current_node->no->no) != NULL)
			{
				puts("moving down in the tree");
				current_node=current_node->no;
				continue;
			}
			
			printf("\n%s? (y/n)\n",current_node->no->quest);	
			scanf("%s",ans);
			if(yes_no(ans))
			{
			 puts("Suspect Identified \nrun again (y/n):");
			 scanf("%s",ans);

			 	if(yes_no(ans))
			 	{
					break;
			 	}			 
			 	else
			 	{
					 return 0;
			 	}
			}
			else
			{
				puts("who's the suspect");
			//	scanf("%s[^\n]",n);
			 	getchar();
				fgets(n,20,stdin);
				//printf("%s",q);
				printf("give me a question that is TRUE for %s but for %s\n",n,current_node->no->quest);
				
			 //	getchar();
			//	getchar();
				fgets(q,70,stdin);
				
				node* node_to_merge =create(q);
				node_to_merge->yes= create(n);
				
				node* temp_node=current_node->no;

				//temp_node=first_node->no;
				current_node->no=node_to_merge;
				node_to_merge->no= temp_node;
				

//				printf("no =%s\nyes=%s\nq=%ss",node_to_merge->no->quest,node_to_merge->yes->quest,node_to_merge->quest);
				

				puts("Run again (y/n)");
				scanf("%s",ans);

				if(yes_no(ans))
				{
					break;
				}
				else
				{
					return 0;
				}

			}

		}
		//	puts("no");
			
		

	}
	}

	release(first_node);

	return 0;

}

