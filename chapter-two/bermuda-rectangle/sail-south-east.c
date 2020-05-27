/*
 * this is to understand pointer 
 * for the record this is on 27-3-19 at 21:23
 * by Gru the Vmeister
 */

#include <stdio.h>

void sail_south_east(int* lat, int* lon);

int main()
{
	int latitude=30;
	int longitude=30;

	sail_south_east(&latitude,&longitude);
        printf("\n\nAvast!! we are at [lat=%d,lon=%d]\n\n",latitude,longitude);

	return 0;
}

void sail_south_east(int* lat, int* lon)
{
//	printf("\n\nlat=%d,lon=%d\n\n",*lat,*lon);
	(*lat)--;
	(*lon)++;

//	printf("\nafter change \nlat=%d,lon=%d\n\n",*lat,*lon);
}
