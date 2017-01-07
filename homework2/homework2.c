//Robert Fink
//rwfwcb 18074424
//cs2050 
//homework2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct points{
	float axis[2];
	int id;
}Points;

typedef enum{
	SortById,
	SortByXAxis
}SortType;

Points *fill_Array(char* fileName, int* length);
void print_set(Points *set, int number_of_points);
void mergeSort(Points *set, int low, int high, int number_of_points, SortType sort);
void merge(Points *set, int low, int middle, int high, int number_of_points, SortType sort);
int binary_search(Points *set, int number_of_points, int ID_Target);
void range_query_on_x(Points *set, int number_of_points, float mean, float std_dev);

int main(int argc, char* argv[]){
	
	if(argc !=2){
		printf("\nError: exactly 2 arguments required\n");
		return -1;
	}

	//initialize variables
	int length=0, ID_Target;

	Points* aSet = fill_Array(argv[1], &length);

	mergeSort(aSet, 0, length-1, length, SortById);

	print_set(aSet, length);

	printf("\nWhat ID to search for?\n");
	scanf("%d", &ID_Target);

	int result = binary_search(aSet, length, ID_Target);
	if (result == -1) {
		printf("\nID %d not found\n", ID_Target);
		return -1;
	}
	
	printf("%d %f %f \n", aSet[result].id, aSet[result].axis[0], aSet[result].axis[1]);

	//sort by the X axis and then print
	mergeSort(aSet, 0, length-1, length, SortByXAxis);
	printf("\n Sorting on x axis...\n");
	print_set(aSet, length);

	//get an X value and distance from X from user and calculate range
	int x, distance;
	printf("\nEnter an X value and a distance from the X value you would like to return.\n");
	scanf("%d %d", &x, &distance);
	range_query_on_x(aSet, length, x, distance);

	free(aSet);

	return 0;
}


Points *fill_Array(char* fileName, int* length){
	//initialize variables
	int i=0;
	FILE* fp = fopen(fileName, "r");

	//scan in length
	fscanf(fp, "%d", length);

	//malloc for a variable which points to type Points
	Points* aSet = malloc(sizeof(Points) * (*length));

	for(i=0; i<(*length); ++i){
		fscanf(fp, "%d %f %f", &aSet[i].id, &aSet[i].axis[0], &aSet[i].axis[1]);
	}

	fclose(fp);

	return aSet;
}

void print_set(Points *set, int number_of_points){
	//initialize variables
	int i=0;

	for(i=0; i<number_of_points; ++i){
		printf("%d %f %f \n", set[i].id, set[i].axis[0], set[i].axis[1]);
	}
}

void mergeSort(Points *set, int low, int high, int number_of_points, SortType sort){
	//initialize variables
	int middle;

	if((high - low) >= 1){
		
		middle = (low + high) / 2;

		mergeSort(set, low, middle, number_of_points, sort);
		mergeSort(set, middle+1, high, number_of_points, sort);

		merge(set, low, middle, high, number_of_points, sort);
	}
}

void merge(Points *set, int low, int middle, int high, int number_of_points, SortType sort){
	//initialize variables
	int i, j, k, m;
	j = low;
	m = middle+1;

	//create temp arrays
	Points tempArray[number_of_points];

	if(sort==SortById){
		for( i=low; j<=middle && m<=high; i++){
			if(set[j].id <= set[m].id){
				tempArray[i] = set[j];
				j++;
			}
			else{
				tempArray[i] = set[m];
				m++;
			}
		}

		if(j>middle){
			for(k=m; k<=high; k++){
				tempArray[i] = set[k];
				i++;
			}
		}
		else{
			for(k=j; k<=middle; k++){
				tempArray[i] = set[k];
				i++;
			}
		}

		for(i=low; i<=high; i++){
			set[i] = tempArray[i];
		}
	}

	//sort on X axis
	if(sort==SortByXAxis){
		for( i=low; j<=middle && m<=high; i++){
			if(set[j].axis[0] <= set[m].axis[0]){
				tempArray[i] = set[j];
				j++;
			}
			else{
				tempArray[i] = set[m];
				m++;
			}
			}

			if(j>middle){
				for(k=m; k<=high; k++){
					tempArray[i] = set[k];
					i++;
				}
			}
			else{
				for(k=j; k<=middle; k++){
					tempArray[i] = set[k];
					i++;
				}
			}

		for(i=low; i<=high; i++){
			set[i] = tempArray[i];
		}
	}
}


int binary_search(Points *set, int number_of_points, int ID_Target){
	int lo = 0;
	int hi = number_of_points - 1;

	if(lo>hi){
		return -1;
	}

	while(lo<=hi){
		int middle = (lo + hi) / 2;

		if(hi - lo == 1){	//if no exact match has been found return closest
			if( abs(set[lo].id - ID_Target) < abs(set[hi].id - ID_Target) ){
				return lo;
			} 
			else{
				return hi;
			}
		}

		if(set[middle].id==ID_Target){
			return middle;//return index of the element found
		}
		else if(set[middle].id>ID_Target){
			hi = middle - 1;
		}
		else if(set[middle].id<ID_Target){
			lo = middle + 1;
		}
	}
	return -1;
}

void range_query_on_x(Points *set, int number_of_points, float mean, float std_dev){
	int i, lo = 0;
	int hi = number_of_points - 1;
	int index = 0;

	if(lo>hi){
		return;
	}
	while(lo<=hi){

		if(hi - lo == 1){
			index = -1;
		}
		int middle = (lo + hi) / 2;
		if(set[middle].axis[0]==mean){
			index = middle;//return index of the element found
			break;
		}
		else if(set[middle].axis[0]>mean){	//set new hi boundary
			hi = middle - 1;
		}
		else if(set[middle].axis[0]<mean){	//set new lo boundary
			lo = middle + 1;
		}
	}

	if(index != -1){
		//create temp array to hold range
		Points tempArray[number_of_points];

		//create variables for lowest and highest index
		int low_end = index - std_dev;
		int high_end = index + std_dev;

		//loop through and print range from mean
		for(i=low_end; i<=high_end; ++i){
			if (i==number_of_points)	//if at edge of array break
				break;
			if (low_end<0){	//if stepping out of array, adjust boundaries
				low_end=0;
				high_end = high_end - (std_dev - mean);
			}

			tempArray[i] = set[low_end++];
			printf("%d %f %f\n", tempArray[i].id, tempArray[i].axis[0], tempArray[i].axis[1]);
		}
	}

	if(index == -1){
		puts("The X value entered was not found");
	}

}


