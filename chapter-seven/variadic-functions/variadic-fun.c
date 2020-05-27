/*
 * this was right after array of functions this is variadic functions and how to use it 
 * basically you will have to specify one fixed parameter for variadic functions this is achieved using macros .macros are not functions they will be replaced by preprocessors with some special code.and this happens before compilation ofcourse
 * now the code follows
 * by gru the vmeister
 */

#include <stdarg.h>
#include <stdio.h>


double total(int a,...);

enum drink{
MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};


double price(enum drink d);

double price(enum drink d)
{
switch(d) {
case MUDSLIDE:
return 6.79;
case FUZZY_NAVEL:
return 5.31;
case MONKEY_GLAND:
return 4.82;
case ZOMBIE:
return 5.89;
}
return 0;
}

double total(int a,...)
{
	int i;
	double total=0;
	va_list l;
	va_start(l,a);
	for(i=0;i<a;i++)
	{
		total+=va_arg(l,double);

	}
	printf("\ntotal=%f\n",total);
	va_end(l);
	return total;
}

int main()
{
	total(3,price(MUDSLIDE),price(ZOMBIE),price(MONKEY_GLAND));


	return 0;
}
