//#ifndef "fish-details-fun_h"
//#define "fish-details-fun_h"


typedef struct{
char* description;
float duration;
}exercise;


typedef struct{
char* ingredients;
float weight;
}meal;


typedef struct{
	exercise exercise;
	meal food;
}preference;



typedef struct{
	char* name;
	char* species;
	int age;
	int teeth;
	preference p;
	}fish;



void catalog(fish);

//#endif
