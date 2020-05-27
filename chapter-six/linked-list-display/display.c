/*
 * this is about linked list
 * first thing array of struct is of a fixed length that is why linked list
 * linked list is easier when needed to add one more link on the list unlike in arrays where the size is fixed but when needed to add or access a link in the linked list everytime the link has to start from the first data and then move on until the nth data or link, unlike in array where it can be dierectly accesed through index number
 * so a linked list is possible through a fine tuning done in struct variable that is making it recursive by adding a struct * variable that points to the same struct .that pointer cannot be a struct variable of the same type coz C has to know how much memory the struct is going to take .so struct * recursive
 * By gru the vmeister
 */

#include <stdio.h>

typedef struct island{
	char* name;
	char* opens;
	char* closes;
	 struct island *next;
}island;

void display(island*);

void display(island *land)
{
	 island *i =land;

	puts("struct island tour details:");
	for(;i!=NULL;i=i->next)
	{
		printf("\nname:%s\nopens:%s\ncloses:%s\n",i->name,i->opens,i->closes);

	}
}

int main()	
{
	 island amity={"amity","5:00 a.m","7:00 p.m",NULL};
	 island craggy={"craggy","7:00 a.m","8:00 p.m",NULL};
	 island isla_nubular={"isla_nubular","8:00 a.m","9:00 p.m",NULL};
	 island shutter={"shutter","9:00 a.m","10:00 p.m",NULL};

	amity.next=&craggy;
	craggy.next=&isla_nubular;
	isla_nubular.next=&shutter;

	display(&amity);
	
	struct island skull={"skull","10:00 a.m","11:00 p.m",NULL};
	craggy.next=&skull;
	skull.next=&isla_nubular;

	display(&amity);
	return 0;

}



