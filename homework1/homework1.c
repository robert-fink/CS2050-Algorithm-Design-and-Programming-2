//Robert Fink
//rwfwcb
//Homework1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 20

typedef struct{
	int year;
	char* make;
	char* model;
	int miles;
}Car;

void fill_garage(Car** garage, char* cars, int* size);
int equals(Car* car, int year, char* make, char* model);
void drive_cars(Car* garage, int* num_cars, char* driving_records);
void store_car_statistics(Car* garage, int num_cars, char* outFile);
void empty_garage(Car* garage, int num_cars);

int main(int argc, char* argv[]){
	if(argc!=4){
		printf("Invalid number of arguments\n");
		return -1;
	}

	//initialize variables
	int size;
	Car* garage = NULL;

	fill_garage(&garage, argv[1], &size);
	drive_cars(garage, &size, argv[2]);
	store_car_statistics(garage, size, argv[3]);
	empty_garage(garage, size);

	return 0;
	
}

void fill_garage(Car** garage, char* cars, int* size){
	//initialize variables
	int i=0;
	
	FILE* fp = fopen(cars, "r");
	if(fp==NULL){
		printf("\nError: pointer returns NULL");
	}

	//read the first line containing size value
	fscanf(fp, "%d", size);

	*garage = malloc(sizeof(Car) * (*size));

	for(i=0; i<(*size); ++i){
		(*garage)[i].make = malloc(sizeof(char) * MAX_STRING_LEN);
		(*garage)[i].model = malloc(sizeof(char) * MAX_STRING_LEN);
		fscanf(fp, "%d %s %s %d", &(*garage)[i].year, (*garage)[i].make, (*garage)[i].model, &(*garage)[i].miles);
	}

	//close file
	fclose(fp);
}

int equals(Car* car, int year, char* make, char* model){
		if((car->year==year) && (strcmp(car->make, make) == 0) && (strcmp(car->model, model) == 0)){
					return 1;
				}
		return 0;
}

void drive_cars(Car* garage, int* num_cars, char* driving_records){
	//initialize variables
	int i=0, j=0, length=0;
	int tempYear=0, tempMiles=0;
	char tempMake[MAX_STRING_LEN], tempModel[MAX_STRING_LEN];

	FILE* fp = fopen(driving_records, "r");
	if(fp==NULL){
		printf("\nError: pointer returns NULL");
	}

	//read the first line containing length value
	fscanf(fp, "%d", &length);

	//scan driving_record information and update records accordingly, if car exists
	for(i=0; i<length; ++i){
		fscanf(fp, "%d %s %s %d", &tempYear, tempMake, tempModel, &tempMiles);
		for(j=0; j<(*num_cars); ++j){
			int eql = equals(&garage[j], tempYear, tempMake, tempModel);
			if (eql == 1){
				garage[j].miles += tempMiles;
			}
		}
	}
	fclose(fp);
}

void store_car_statistics(Car* garage, int num_cars, char* outFile){
	//initialize variables
	int i=0;

	FILE* fp = fopen(outFile, "w");

	//write to output file
	for(i=0; i<num_cars; ++i){
		fprintf(fp, "%d %s %s %d\n", garage[i].year, garage[i].make, garage[i].model, garage[i].miles);
	}

	//close file
	fclose(fp);

}

void empty_garage(Car* garage, int num_cars){
	//initialize variables
	int i=0;

	//free all allocated memory
	for(i=0; i<num_cars; ++i){
		free(garage[i].make);
		free(garage[i].model);
	}
	free(garage);
}
