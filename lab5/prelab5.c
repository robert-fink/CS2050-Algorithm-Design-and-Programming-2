//Robert Fink
//Prelab5
//cs2050

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE 20

void load_accounts(int array[], char* inputFile);
void bubbleSort(int array[], int length);
void mergeSort(int array[], int length);
void sortSubArray(int array[], int low, int high);
void merge(int array[], int left, int middle1, int middle2, int right);
int binary_search(int array[], int low, int high, int key);
void insertion_sort(int array[], int length);

int main(int argc, char* argv[]){
	int a[MAX_ARRAY_SIZE];
	int i=0, key, index;
	load_accounts(a, argv[1]);

	puts("Unsorted array");
	for(i=0; i<MAX_ARRAY_SIZE; ++i){
		printf("%d ", a[i]);
	}
	puts("");
	
	//bubbleSort(a, MAX_ARRAY_SIZE);
	//mergeSort(a, MAX_ARRAY_SIZE);
	insertion_sort(a, MAX_ARRAY_SIZE);
	
	puts("Sorted array");
	for(i=0; i<MAX_ARRAY_SIZE; ++i){
		printf("%d ", a[i]);
	}
	puts("");

	printf("Enter the value to search for: ");
	scanf("%d", &key);

	index = binary_search(a, 0, MAX_ARRAY_SIZE, key);
	if(index == -1)
		printf("Key not found\n");
	if(index != -1){
		printf("Key %d found at index %d\n", key, index);
	}



}

void load_accounts(int array[], char* fileName){
	FILE* fp = fopen(fileName, "r");
	int i=0;

	for(i=0; i<MAX_ARRAY_SIZE; ++i){
		fscanf(fp, "%d", &array[i]);
		if(feof(fp)){
			break;
		}
	}
}

void bubbleSort(int array[], int length){
	int i=0, j=0, temp;
	for(j=0; j<MAX_ARRAY_SIZE; ++j){
		for(i=0; i<MAX_ARRAY_SIZE-1; ++i){
			if(array[i] > array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	}
}

void mergeSort(int array[], int length){
	sortSubArray(array, 0, length-1);
}

void sortSubArray(int array[], int low, int high){
	int middle1, middle2;

	if((high - low) >= 1){
		middle1 = (low + high) / 2;
		middle2 = middle1 +1;

		sortSubArray(array, low, middle1);
		sortSubArray(array, middle2, high);

		merge(array, low, middle1, middle2, high);
	}
}

void merge(int array[], int left, int middle1, int middle2, int right){
	int leftIndex = left;
	int rightIndex = middle2;
	int combinedIndex = left;
	int tempArray[MAX_ARRAY_SIZE];
	int i=0;

	while((leftIndex <= middle1) && (rightIndex <= right)){
		if(array[leftIndex] <= array[rightIndex])
			tempArray[combinedIndex++] = array[leftIndex++];
		else
			tempArray[combinedIndex++] = array[rightIndex++];
	}

	if(leftIndex == middle2){
		while(rightIndex <= right)
			tempArray[combinedIndex++] = array[rightIndex++];
	}
	else{
		while(leftIndex <= middle1)
			tempArray[combinedIndex++] = array[leftIndex++];
	}

	for(i=0; i<=right; ++i){
		array[i] = tempArray[i];
	}
}

int binary_search(int array[], int low, int high, int key){
	int middle = (low + high) / 2;

	if(low>high){
		return -1;
	}

	if(array[middle] == key){
		printf("Key %d found at index %d", key, middle);
		return middle;
	}

	if(array[middle] > key){
		return binary_search(array, low, middle-1, key);
	}

	else if(array[middle] < key){
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
			array[moveItem] = insert;
	}
}	

int fib(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return(fib(n-1) + fib(n-2));
		}
