//Robert Fink
//rwfwcb
//prelab2

#define SIZE 3
#include <stdlib.h>
#include <stdio.h>


typedef struct pair_t{
	int x;
	int y;
}pair_t;

pair_t* readFile(char* inputfile);
void sum(pair_t* number);


int main(int argc, char* argv[]){
	pair_t* filePtr = readFile(*(argv + 1));
	sum(filePtr);

	return 0;
}

pair_t* readFile(char* inputFile){
	//initialize variables
	int i=0;
	
	//dynamically create structure array
	
	pair_t number[SIZE];
	pair_t* numberPtr = &number[0];
	numberPtr = malloc(SIZE * sizeof(pair_t));

	//pair number[3];
        //for(i = 0; i < 3; i++)
	//{
	//	number[i] = malloc(sizeof(pair_t));
	//}
	//open the file and read pairs into array
	FILE* fPtr = fopen(inputFile, "r");

	for(i=0; i<SIZE; ++i){
		fscanf(fPtr, "%d %d", &numberPtr[i].x, &numberPtr[i].y);
	}

	return numberPtr;
}

void sum(pair_t* number){
	//intitialize variables
	int i=0, temp=0; 
	
	//for loop to sum pairs into temporary array
	for(i=0; i<SIZE; i++){
		temp = number[i].x + number[i].y;
		printf("\n%d\n", temp);

		//*(Pair[i]).x + *(Pair[i]).y = temp[i];
		//Pair[i]->x + Pair[i]->y = temp[i];
	}
}

