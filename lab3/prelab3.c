//Robert Fink
//rwfwcb
//Prelab3

#include <stdlib.h>
#include <stdio.h>

typedef struct account{
	int accountId;
	char* name;
	double amount;
	}account;
	
struct account* read_file(char* file_name);
//void print(account*, int size);

int main(int argc, char* argv[]){
	
	account* array = read_file(argv[1]);
	
	//print(array, size);
	
	return 0;
}

account* read_file(char* file_name){
		//initialize variables
		int i=0, size = 0;
		
		//create file pointer and open file
		FILE* file_ptr = fopen(file_name, "r");
		
		//read the first line containing length value
		fscanf(file_ptr, "%d", &size);
		
		//malloc a struct account array
		
		account* array = NULL;
		array = malloc(size * sizeof(account));
		
		
		
		//for loop to read into structure array
		for(i=0; i<size; ++i){
			array[i].name = malloc(sizeof(char)* 10);
			fscanf(file_ptr, "%d %s %lf", &array[i].accountId, array[i].name, &array[i].amount);
		}
		
		//close the file
		fclose(file_ptr);

		//for loop through array and print output
		for(i=0; i<size; ++i){
			printf("%d %s %.2lf\n", array[i].accountId, array[i].name, array[i].amount);
		}
		return array;
}

/*void print(account* array, int size){
	//initialize variables
	int i=0;
	
	//for loop through array and print output
	for(i=0; i<size; ++i){
		printf("%d %s %f\n", array[i].accountId, array[i].name, array[i].amount);
	}
}
*/
