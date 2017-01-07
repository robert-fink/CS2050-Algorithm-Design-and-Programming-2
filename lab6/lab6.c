//Robert Fink
//lab6
//labcode: SPACE
//cs2050

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

typedef struct{
	unsigned long int comparisons;
	unsigned long int swaps;
	long double duration;
	}SortStat;
	
typedef struct{
	int* first;
	int* second;
	int* third;
}Arrays;

Arrays generate_arrays(int len);
SortStat bubble_sort(int arrays[], int len);
SortStat selection_sort(int arrays[], int len);
void swap(int arrays[], int first, int second);
SortStat insertion_sort(int array[], int length);
void free_memory(Arrays array, int len);
void display_array(Arrays array, int len);


int main(){
	//initialize variables
	int i;
	//struct timeval tv;
	//double t1, t2, duration;
	
	/*
	printf("Enter the length for arrays: ");
	scanf("%d", &length);

	Arrays array = generate_arrays(length);
	*/
	
	for(i=1; i<=4; ++i){
		int length = (int)pow(10, i);
		Arrays array = generate_arrays(length);
		
		printf("\n\nFor arrays of size %d", length);
		
		SortStat bubbleStats = bubble_sort(array.first, length);
		printf("\nBubble sort make %lu comparisons, %lu swaps and took %Le milliseconds", bubbleStats.comparisons, bubbleStats.swaps, bubbleStats.duration);
	
		SortStat selectionStats = selection_sort(array.second, length);
		printf("\nSelection sort make %lu comparisons, %lu swaps and took %Le milliseconds", selectionStats.comparisons, selectionStats.swaps, selectionStats.duration);
		
		SortStat insertionStats = insertion_sort(array.third, length);
		printf("\nInsertion sort make %lu comparisons, %lu swaps and took %Le milliseconds\n", insertionStats.comparisons, insertionStats.swaps, insertionStats.duration);
		
		free_memory(array, length);
	}
	
	/*
	SortStat bubbleStats = bubble_sort(array.first, length);
	printf("\nBubble sort make %lu comparisons, %lu swaps and took %Lf milliseconds", bubbleStats.comparisons, bubbleStats.swaps, bubbleStats.duration);
	
	SortStat selectionStats = selection_sort(array.second, length);
	printf("\nSelection sort make %lu comparisons, %lu swaps and took %Lf milliseconds", selectionStats.comparisons, selectionStats.swaps, selectionStats.duration);
	
	SortStat insertionStats = insertion_sort(array.third, length);
	printf("\nInsertion sort make %lu comparisons, %lu swaps and took %Lf milliseconds\n", insertionStats.comparisons, insertionStats.swaps, insertionStats.duration);
	*/
	
	//free_memory(array, length);

	return 1;

}//end of main


SortStat bubble_sort(int array[], int length){
	int i=0, j=0, temp;
	SortStat stats;
	stats.comparisons=0;
	stats.swaps=0;
	stats.duration=0;
	struct timeval tv;
	double t1, t2;
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);
	
	for(j=0; j<length; ++j){
		for(i=j+1; i<length; ++i){
		stats.comparisons++;
			if(array[i] > array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				stats.swaps++;
			}
		}
	}
	
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	stats.duration = (t2 -t1) *1000; //*1000 convert secs to millisecs
	
	return stats;
}

SortStat selection_sort(int array[], int length){
	//initialize variables
	int smallest;
	int i, j;
	
	SortStat stats;
	stats.comparisons=0;
	stats.swaps=0;
	stats.duration=0;
	struct timeval tv;
	double t1, t2;
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);
	
	for(i=0; i<length; ++i){
		smallest = i;
		for(j=i+1; j<length; ++j){
			stats.comparisons++;
			if(array[j] < array[smallest])
				smallest = j;
		}		
		swap(array, i, smallest);		//swap smallest element
		stats.swaps++;
	}

	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	stats.duration = (t2 -t1) *1000; //*1000 convert secs to millisecs
	
	return stats;
}

void swap(int array[], int first, int second){
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
	}

SortStat insertion_sort(int array[], int length){
	int insert, i;
	SortStat stats;
	stats.comparisons=0;
	stats.swaps=0;
	stats.duration=0;
	struct timeval tv;
	double t1, t2;
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);
	
	for(i=1; i<length; ++i){
		int moveItem = i;
		insert = array[i];
		
		stats.comparisons++;
		//search for place to put current element
		while(moveItem > 0 && array[moveItem - 1] > insert){
			//shift element right one slot
			array[moveItem] = array[moveItem - 1];
			--moveItem;
		}
			array[moveItem] = insert;
			stats.swaps++;
	}
	
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	stats.duration = (t2 -t1) *1000; //*1000 convert secs to millisecs
	
	return stats;
}	
	
void display_array(Arrays array, int len){
	int i=0;
	
	for(i=0; i<len; ++i){
		printf("%d ", array.first[i]);
	}
	puts("");

}

Arrays generate_arrays(int len){
	int i=0;
	srand(time(NULL));
	Arrays array1;
	
	array1.first = malloc(sizeof(int) * len);
	array1.second = malloc(sizeof(int) * len);
	array1.third = malloc(sizeof(int) * len);

	
	for(i=0; i<len; ++i){
		int val = rand() % len+1;
		array1.first[i] = val;
		array1.second[i] = val;
		array1.third[i] = val;
	}
	return array1;

}

void free_memory(Arrays array, int len){
		free(array.first);
		free(array.second);
		free(array.third);
}


