/*
 * this is a crossword puzzle it uses array of pointers rather than array of arrays
 * by Gru the Vmeister
 * on 29-3-20 at 00:34
 */

#include <stdio.h>
#include <string.h>


void reverse_a_string(char *s);

void reverse_a_string(char *s)
{
	size_t len=strlen(s);

	char *t =s+(len-1);
	
	while(len--)
	{
		printf("%c",*t);
		t--;
	}
	puts("");

}

int main()
{
	char *fruit[]={"dragonfruit","waterberry","sharonfruit","uglifruit","rumberry","kiwifruit","mulberry","strawberry","blueberry","blackberry","starfruit"};

	char *a;

	//1
	puts(fruit[6]);
	//2
	reverse_a_string(fruit[7]);
	//3
	puts(fruit[2]);
	//4	
	reverse_a_string(fruit[5]);
	//5	
	puts(fruit[8]);
	//6
	reverse_a_string(fruit[9]);
	//7
	puts(fruit[10]);
	//8	
	reverse_a_string(fruit[3]);

	return 0;
}
	
