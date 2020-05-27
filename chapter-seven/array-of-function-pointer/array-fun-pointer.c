/*
 * this is to revise function pointer 
 * i remember i can do it
 * by gru the vmeister
 */

#include <stdio.h>

typedef enum{DUMP,SECOND_CHANCE,MARRIAGE}type;

typedef struct{
	char *name;
	type msg;
}response;

void dump(response r)
{
	printf("\nDear %s,\n",r.name);
	puts("Unfortunately your last date contacted us he/she wanted us to tell you to not call her anymore");
}

void second_chance(response r)
{
	printf("\nDear %s,\n",r.name);
	puts("Good news :your last date wants to fix another date call him/her");
}

void marriage(response r)
{
	printf("\nDear %s,\n",r.name);
	puts("Congrats: your date has come up with a proposal he/she wants to marry you \n FIN");
}
void (*fun[])(response)={dump,second_chance,marriage};


int main()
{
	response r[]={{"ken",DUMP},{"Ben",SECOND_CHANCE},{"cate",MARRIAGE}};
	int i;

	for(i=0;i<3;i++)
	{
	 	fun[r[i].msg](r[i]);	
	}
}
