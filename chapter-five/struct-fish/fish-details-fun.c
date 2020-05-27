#include "fish-details-fun.h"

void catalog(fish f2)
{
printf("\n\n%s is a %s .He is %i.He has %i teeth\n",f2.name,f2.species,f2.age,f2.teeth);
}

void label(fish f2)
{
	printf("\nName: %s\nSpecies :%s\nExercise description: %s\nExercise duration: %fhours\nfood ingredients: %s\nfood weight: %f kg\n",f2.name,f2.species,f2.p.exercise.description,f2.p.exercise.duration,f2.p.food.ingredients,f2.p.food.weight);	
}
