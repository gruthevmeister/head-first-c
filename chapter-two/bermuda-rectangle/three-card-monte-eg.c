
/*
 * this is a program to clear the doubt about the difference of array variables and pointer variables
 * as we know there wont be any space allocated for array variables hence &array variables == array variables
 * whereas for a pointer &pointer !=pointer 
 * also we saw the difference between scanf() and fgets(). scanf can take multiple inputs in a structured way(like the example with the space) but fgets cannot.
 * scanf() is a problem when the user types longer than the buffer size provided
 *
 * okay lets get back to how variables are stored in memory 
 * when declared a string literal as char *st="JQK" the strin"JQK" will be stored in read only memory region of the processes allocated memory so when changed to modify the contents of it . it will throw an error .
 * so as to come across this declare as char st[]="JQK" and define immediately coz it doesnt have the buffer size mentioned 
 * when done so the string literal will be stored in read only memory and the array variable in stack will have a copy of it as an array and the contents can be changed
 * variables declared inside main will be in stack region of the memory and the ones outside will be in global section of memory
 */


#include <stdio.h>

int main()
{
	char monte[]="JQK";
	char temp=monte[2];

	monte[1]=monte[2];
	
	monte[2]=monte[0];

	monte[0]=temp;

        printf("monte:%s\n",monte);
}
