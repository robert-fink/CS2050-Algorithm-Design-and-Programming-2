//Robert Fink
//lab5
//labcode: inception
//cs2050

#include <stdio.h>
#include <stdlib.h>

int* load_array(char* file, int* length);
void insertion_sort(int array[], int length);
int binary_search(int array[], int low, int high, int key);
int fib(int n);
int range(int array[], int length, int low, int high);

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Error: exactly 2 arguments required\n");
		return -1;
	}
	
	int length, key, i=0;
	int low, high;
	int* array = load_array(argv[1], &length);
	
	insertion_sort(array, length);
	
	for(i=0; i<length; ++i){
		array[i] = fib(array[i]);
	}
	
	for(i=0; i<length; ++i){
		printf("%d\n", array[i]);
	}
	
	printf("\nEnter a key to search for: ");
	scanf("%d", &key);
	
	int index = binary_search(array, 0, length, key);
	
	if(index == -1){
		printf("Key not found\n");
	}
	if(index != -1){
		printf("Key %d found at index %d\n", key, index);
	}
	
	printf("Bonus: Enter a range to search for: ");
	scanf("%d %d", &low, &high);
	
	int rangeCount = range(array, length, low, high);
	printf("\nThere are %d numbers between %d and %d inclusively\n", rangeCount, low, high);

	
	return 1;
}

int* load_array(char* inputFile, int* size){
	FILE* fp = fopen(inputFile, "r");	//create filePointer and open file
	int i=0;
	
	fscanf(fp, "%d", size);
	
	int* accounts = malloc(sizeof(int) * (*size));	//allocate memory for accounts array
	
	for(i=0; i<*size; i++){
		fscanf(fp, "%d", &accounts[i]);
	}
	
	fclose(fp);
	
	return accounts;
	
}

int binary_search(int array[], int low, int high, int key){ //binary search for a given key in the array
	int middle = (low + high) / 2;

	if(low>high){
		return -1;
	}

	if(array[middle] == key){ //if equal to middle, return 
		return middle;
	}

	if(array[middle] > key){ //check lower half of array
		return binary_search(array, low, middle-1, key);
	}

	else if(array[middle] < key){ //check upper half of array
		return binary_search(array, middle+1, high, key);
	}
	else{
		return -1;
	}
}

void insertion_sort(int array[], int length){
	int insert, i;
	
	for(i=1; i<length; ++i){
		int moveItem = i;
		insert = array[i];
		
		//search for place to put current element
		while(moveItem > 0 && array[moveItem - 1] > insert){
			//shift element right one slot
			array[moveItem] = array[moveItem - 1];
			--moveItem;
		}
			array[moveItem] = insert;	//insert element
	}
}	

int fib(int n){
	//return fibonacci number
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return(fib(n-1) + fib(n-2));
		}
}

int range(int array[], int length, int low, int high){
	//return range of numbers in array inclusively
	return binary_search(array, 0, length-1, high) - binary_search(array, 0, length-1, low) +1;
}
	