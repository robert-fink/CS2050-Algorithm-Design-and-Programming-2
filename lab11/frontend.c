//Robert Fink
//rwfwcb
//cs2050
//labcode: The End

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 250

int is_phone_number(char* word);
int is_date(char* word);
int looks_like_name(const char* word);
int is_email(char* word);

int main(int argc, char* argv[]){
	//initialize variables
	char buffer[MAX_LINE];
	char *token;
	int counter=0;
	
	char* number;
	char* date;
	char* email;
	char* name;
	
	FILE* fp = fopen(argv[1], "r");
	
	if (fp == NULL){	//check if file is opened successfully
		puts("Error: could not open file");
		return -1;
	}
	
	
	//do fgets to read in a line
	while( fgets(buffer, MAX_LINE, fp)){
		if(buffer[strlen(buffer) -1] == '\n')
			buffer[strlen(buffer) -1] = '\0';
			
		token = strtok(buffer, " ,.\n\t\r");
		
		while (token != NULL){
		//	printf("%s\n", token);
			
			if (is_phone_number(token) == 1){
				printf("Phone number: %s\n", token);
				counter++;
			}
			
			if (is_date(token) == 1){
				printf("Date: %s\n", token);
				counter++;
			}
			
			if (looks_like_name(token) == 1){
				printf("Name: %s\n", token);
				counter++;
			}
			
			if (is_email(token) == 1){
				printf("Email: %s\n", token);
				counter++;
			}
			
			else counter++;
			
			token = strtok(NULL, " ,.\n\t\r");
		
		}
	}
	
	fclose(fp);
	
	
	printf("There are %d words in the file\n", counter);
	
	return 0;
}


	
			
	
	
	
			
	
		
	
	
		
		
		
	