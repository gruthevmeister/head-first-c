/*
 * this is to understand the syntax and proper use of structs unions and enum
 * struct s={.f1=1,.f2=3,{.f1=4}};
 * let me clear this clearly
 * by gru the vmeister
 */

#include <stdio.h>
#include "display-function.h"

int main()
{
	fruit_order f1={"apple","india",.q.count=23,COUNT};

	fruit_order f2={"vplant","india",.q.volume=6,PINT};

	display(&f1);

	display(&f2);
	return 0;

}
