/* 
 * this is an umpteeth revision of C hopefully this is the last time ill finish the book
 * this to record has been written on 27-3-20
 * by Gru the Vmeister
 */

#include <stdio.h>
#include <stdlib.h>

int count=0;

int main()
{
	char card[3]="blu"; //just to test
	int card_value=0;

	while((card[0]!='X'))//||(card[0]!='x'))
	{
		puts("\n Enter card name\n");
		scanf("%2s",card);	

		switch(card[0])
		{
		case 'A': 
			card_value=11;
			break;
	
		case 'K': 
			card_value=10;
			break;
		
		case 'Q': 
			card_value=10;
			break;
	
		case 'J': 
			card_value=10;
			break;

		case 'X':
			continue;

		case 'x':
			return 1;	

		default:
			card_value=atoi(card);

			if(card_value<1 | card_value>11)
			{
				puts("the value entered is wrong");
				continue;
			}		
			break;
		}

     		printf("\n the value of the card is %d\n",card_value);

		if((card_value>=3) && (card_value<=6))
		{
			count++;
			printf("\n Count:%d\n",count);
			puts("count has gone up");
		}
		else if(card_value==10)
       		{
			count--;
			printf("\n Count:%d\n",count);		
			puts("count has gone down");
		}
		else if(card_value>11)
		{
			puts("the number you have entered is wrong\n ");
		}
	}		

	return 0;

}
