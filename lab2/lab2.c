//Robert Fink
//Pawprint: rwfwcb
//Lab code: Jack & Jill
//Lab2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//define structure
struct point{
	int x;
	int y;
	};

//function prototypes	
struct point* read_file(char* file_name, int size);
double distance(struct point first, struct point second);
struct point* sort(struct point* array, int size);
void print_points(struct point* array, int size);

int main(int argc, char* argv[]){
		//initialize variable size
		int size = atoi(argv[2]);
		
		struct point* array = read_file((argv[1]), size);
		struct point* sorted_array = sort(array, size);
		print_points(sorted_array, size);
		
		return 0;
	}
	
struct point* read_file(char* file_name, int size){
	//initialize variables
	int i=0;

	//dynamically create array of structure
	struct point* array = NULL;
	array = malloc(size * sizeof(struct point));
	
	//create pointer to a file and open file
	FILE* fPtr = fopen(file_name, "r");
	
	//for loop to scan through input file
	for(i=0; i<size; ++i){
		fscanf(fPtr, "%d %d", &array[i].x, &array[i].y);
		}
		return array;
	}

double distance(struct point first, struct point second){
//calculate and return distance from given distance equation
return sqrt(pow((first.x - second.x), 2) + pow((first.y - second.y), 2));
}

struct point* sort(struct point* array, int size){
	//initialize variables
	int i=0, j=0;
	struct point temp = {0, 0};
	
	//create origin structure
	struct point origin = {0, 0};
	
	//for loop to bubble sort points based on distance from origin
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			if(distance(array[j], origin) > distance(array[j+1], origin)){
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
			}
		}
	}
	return array;
}	

void print_points(struct point* array, int size){
//initialize variable
int i=0;

//print header
puts("Points sorted based on distance from the origin");

//for loop to print points in ascending order
for(i=0; i<size; ++i){
	printf("(%d, %d)\n", array[i].x, array[i].y);
}
}

//struct point intersection(struct point p1, struct point p2, struct point p3, struct point p4){
//((p1.x * p1.y) - (p1.y * p1.x)) - ((p1.x - p2.x)(p3.x * p4.y - p3.y * p4.x))/ ((p1.x - p2.x)(p3.y - p4.y)) - ((p1.y - p2.y)(p3.x - p4.x))

