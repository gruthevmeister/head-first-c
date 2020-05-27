/*
 * this is to understand struct better struct helps combine different datatypes together 
 * by gru the vmeister
 */

#include <stdio.h>
#include "fish-details-fun.h"

int main()
{
 	fish f1={"snappy","piranha",4,32,{{"lunges",1.0},{"fish_food",1.2}}};
	
//	printf("\nfish catalog:\n%s,\n%s,\n%i,\n%i",f1.name,f1.species,f1.age,f1.teeth);

	catalog(f1);

	label(f1);
	//puts("enter name species age and no. of teeth ");
	
}
