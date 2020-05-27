#ifndef spies_h
#define spies_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char* quest;
	struct node *yes;
	struct node *no;
}node;



int yes_no(char* a);
node* create(char* q);

void display(node*);

void release(node*);

#endif
