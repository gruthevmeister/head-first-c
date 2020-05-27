#include "display-function.h"

void display(fruit_order *f)
{
	printf("this order contains ");
	switch(f->units_of_measure)
	{
		case 0:
			printf("%i %s\n",f->q.count,f->name);
			break;
		case 1:
			printf("%.2f pints of %s\n",f->q.volume,f->name);
			break;
		case 2:
			printf(".2%f kgs of %s\n",f->q.weight,f->name);
			break;
	}
	
}
