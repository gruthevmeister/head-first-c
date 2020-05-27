/*
 * this is to understand how to feed in data dynamically by using malloc 
 * malloc returns a generic void pointer. it almost always is used with sizeof operator in stdlib.h malloc should also be used with free 
 * malloc could be understood as borrowing a locker from the os with the analogy of the key given by the os on request
 * now when passing a name getting the name is stored in array variable since it makes a copy of the string literall in stack and can be modified unlike char*.
 * but the problem when writing a function is the name char * will point to the same address which will be changed by the input names of the other islands
 * so to tackle this issue we use another function strdup in string.h
 * this also uses space in heap so this also has to be freed using free()
 * by gru the vmeister
 */

#include <stdio.h>
#include "linked-list-fun.h"


island* start=NULL;

int main()
{

 	//island amity={"amity","7:00 a.m","9:00 p.m",NULL};
	char *island_name;
	island* temp_island=NULL;

	puts("check");
	// island blues={"blues","7:00 a.m","9:00 p.m",NULL};
         while(scanf("%s",island_name)==1)
	 {      
		 if(*island_name =='x')
			break; 
		 if(temp_island !=NULL)
		 {
		 
		 temp_island->next=create(island_name);
		 temp_island=temp_island->next;
	  //	 puts("check");
		 }
		 else
		 {
		 temp_island=create(island_name);
		 start=temp_island;
		 }
	 }		 
//	 amity.next=create("blues");

	 display(start);

	 release(start);
	 return 0;
}
