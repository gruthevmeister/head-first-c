/*
 * this program is basically to understand how to use function pointer
 * apparently whenever a function the function name itself holds an address
 * this addres can be used to define the function pointer 
 * as different functions are of different types depending on their return value and the number and type of argument the function pointer has to be generic enough to hold them
 * by gru the vmeister
 */

#include <stdio.h>
#include "match-making-fun.h"

int main()
{
	find(sports_no_bieber);
	find(sports_no_bieber);
	find(sports_or_workout);
	find(ns_theatre);
	find(arts_theatre_or_dining);
	return 0;
}
