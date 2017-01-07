//Robert Fink
//Pawprint: rwfwcb
//Lab code: Birthday Cake
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int* readFile(char* inputFile);
int findMin(int* array);
int findMax(int*);
int findAvg(int*);
void writeOut(char* outFile, int min, int max, int avg);
int findMedian(int*);


int main(int argc, char* argv[]){
	int* filePtr = readFile(*(argv+1));
	int minimum = findMin(filePtr);
	int maximum = findMax(filePtr);
	int average = findAvg(filePtr);
	writeOut(*(argv+2), minimum, maximum, average);
	return 0;
}

int* readFile(char* inputFile){
	//initialize variable
	int i=0;
	//malloc to dynamically create array
	int* array1 = (int *) malloc (sizeof(int)*SIZE);

	//create file pointer, open and read input file
	FILE* fp = fopen(inputFile, "r");
	if(fp==NULL){
		return 0;
	}
	printf("not null");
	for(i=0;i<SIZE;++i){
		fscanf(fp, "%d", array1+i);
	}
	fclose(fp);
	return array1;
}

int findMin(int* array){
	//initialize variables
	int i=0, min=100;
	//for loop to find minimum value in array
	for(i=0; i<SIZE; ++i){
		if(*(array+i) <  min){
			min = *(array+i);
		}
	}
	return min;
}

int findMax(int* array){
	//initilize variables
	int i=0, max=-100;
	//for loop to find maximum value in array
	for(i=0; i<SIZE; ++i){
		if(*(array+i) > max){
			max = *(array+i);
		}
	}
	return max;
}

int findAvg(int* array){
	//initialize variables
	int i=0, counter=0, sum=0, avg=0;
	//loop through array and sum together values, then find average
	for(i=0; i<SIZE; ++i){
		sum += *(array+i);
		counter+=1;
	}
	avg = sum/counter;
	return avg;
}

void writeOut(char* outFile, int min, int max, int avg){
	FILE* fp = fopen(outFile, "w");
	if(fp==NULL){
		return;
	}
	fprintf(fp, "min: %d \nmax: %d \navg: %d \n", min, max, avg);
}
