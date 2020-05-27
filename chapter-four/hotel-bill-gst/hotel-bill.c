/*
 * this program is to calculate the bill through the provided price of each
 * this is to learn the use of data types appropriately
 * by gru the Vmeister
 */

#include <stdio.h>

short percent=18;
float total=0;
short count=0;

float add_to_total_with_tax(float val);


float add_to_total_with_tax(float val)
{
	total =total + (val*(1+ percent/100.0));
	count++;
	return total;
}

int main()
{
	float f=0;
	puts("price of the item:");
	while(scanf("%f",&f) ==1)
	{
		printf("\ntotal so far:%.3f \n",add_to_total_with_tax(f));
	        puts("price of the item");	
	}
	printf("\nnumber of items :%hi\n",count);
	printf("\ngrand Total:%.3f\n",total);

return 0;	
}
