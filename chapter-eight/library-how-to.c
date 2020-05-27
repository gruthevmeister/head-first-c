/*
 * this is to understand how to make custom libraries and share them in all code .
 * so ususally all the standard libraries are stored in /usr/include or /usr/local/include 
 * here we use and example of how to convert a .h file and .o files and put them into the std library 
 * first way is to create a dierectoy in /(root) and name a custom name for eg /my_inc and put your .h files there 
 * and then while compiling in gcc use -I /my_inc .
 * here we also are sharing the object files ,so as to do that you simply have to create another dierectory named my_obj files
 * and use -I switch like /my_obj while using gcc
 * by gru the vmeister
 */
//#include <stdio.h>
#include "/my_inc/encrypt.h"
#include "/my_inc/checksum.h"

int main()
{
	int check_sum;
	char code[]="say friend and enter";

	puts("encrypted:");
	encrypt(code);
	check_sum=checksum(code);
	printf("\tchecksum=%i",check_sum);
	puts("Decrypted:");
		
	encrypt(code);
	check_sum=checksum("love");
	printf("\tchecksum=%i",check_sum);
	
	return 0;
}

