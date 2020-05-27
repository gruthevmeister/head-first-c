/*
 * this is to understand bitfields 
 * important note to use bit fields the data type of the variable should be unsigned int followed by a variable name follwed by a colon:"specifying number of bits"
 * by gru the vmeister
 */

#include <stdio.h>

typedef struct
{
       	unsigned int first_visit:1;
	unsigned int come_again:1;
	unsigned int fingers_lost:4;
	unsigned int lost_a_child:1;
	unsigned int no_of_visits_a_week:3;
}survey_details;

/*this ends abruptly in the book *sad */
