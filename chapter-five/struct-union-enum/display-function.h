

typedef enum{
	COUNT,PINT,POUNDS
}unit;

typedef union{
	int count;
	float weight;
	float volume;
}quantity;

typedef struct{
	char *name;
	char *country;
	quantity q;
	unit units_of_measure;
}fruit_order;

void display(fruit_order *f);
