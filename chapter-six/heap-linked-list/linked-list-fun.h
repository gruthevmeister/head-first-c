#ifndef linked_list_fun
#define linked_list_fun

#include <stdlib.h>
#include <string.h>
typedef struct island
{
	char* name;
	char* opens;
	char* closes;
	struct island *next;
}island;

void display(island*);
island* create(char* n);
void release(island* i);

#endif
