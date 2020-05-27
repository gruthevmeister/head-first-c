/*
 * this is to understand strings are arrays of characters as told in chapter 1
 * it has a sentinal character at the end 
 * so when declaring a pointer always decide the index value to be plus one than intended number of array values for the compiler to fill in the sentinal character
 * now a string is passed to a function and the argument can be declared as char str[]
 * by Gru the Vmeister
 */

#include <stdio.h>

void printmsg(char msg[]);

int main()
{
	char quote[]="to think is to not think";

	printmsg(quote);

	return 0;
}

void printmsg(char msg[])
{
	printf("\nMessage:%s\nsize of messege:%i\n",msg,sizeof(msg));
}
