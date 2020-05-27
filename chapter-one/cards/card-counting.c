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
	char card[3];
	int card_value=0;

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

	default:
		card_value=atoi(card);
		break;
	}

//	printf("\n the value of the card is %d\n",card_value);

	if((card_value>=3) && (card_value<=6))
	{
		count++;
		printf("\n Count:%d\n",count);
	}
	else if(card_value==10)
        {
		count--;
		printf("\n Count:%d\n",count);
	}

	return 0;

}
