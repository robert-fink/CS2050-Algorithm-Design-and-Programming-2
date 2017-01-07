//Robert Fink
//rwfwcb
//cs2050
//Homework4

#define SIZE 20
#define MAX_LINE 250

#include "analysis.h"

void sentiment_analysis(char* file, node* neg, node* pos){
	//initialize variables
	char buffer[MAX_LINE];
	int pcount=0;
	int ncount=0;
	char *token;

	FILE* fp = fopen(file, "r");
	
	if (fp == NULL){	//check if file is opened successfully
		puts("Error: could not open file");
		return;
	}
	
	//do fgets to read in a line
	while( fgets(buffer, MAX_LINE, fp)){

		if(buffer[strlen(buffer) -1] == '\n')
			buffer[strlen(buffer) -1] = '\0';
		
		//tokenize word by word on spaces and newlines
		token = strtok(buffer, " \n");
		
		while (token != NULL){
			//if is_positive equals 1, word is positive
			if (is_positive(token, pos) == 1){
				pcount++;
			}
			//if is_negative equals 1, word is negative
			if (is_negative(token, neg) == 1){
				ncount++;
			}
			
			//walk through tokens
			token = strtok(NULL, " ,.\n\t\r");
		
		}
		
		if (pcount > ncount){
			printf("This is a positive review\n\n");
		}
		else{
			printf("This is a negative review\n\n");
		}

	}
	
	fclose(fp);

}
int is_positive(char* word, node* pos){
	node* temp = pos;
	
	//compare word to positive words list
	//if word is a match return 1
	while (temp != NULL){
		if (strcmp(word, temp->word) == 0){
			return 1;
		}
		temp = temp->next;	
	}
	return 0;
}

int is_negative(char* word, node* neg){
	node* temp = neg;
	
	//compare word to negative words list
	//if word is a match return 1
	while (temp != NULL){
		if (strcmp(word, temp->word) == 0){
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

node* insert_at_head(node* head, char* word){
	// malloc for a new node and attach to linked list
	node *new_node;
	
	new_node = (node*)malloc(sizeof(node));
	new_node->word = word;
	new_node->next = head;

	return new_node;
}

node* create_list(char* file){
	//initialize variables
	int i=0;
	node* head = NULL;
	char* word = NULL;

	FILE* fp = fopen(file, "r");
	
	//check if file opens successfully
	if(fp==NULL)
		puts("Error: unable to open the file");
	
	while(1){
		word = (char*)malloc(sizeof(char) * 20);
		fscanf(fp, "%s", word);
		head = insert_at_head(head, word);
		if(feof(fp)){
			break;
		}
	}
	
	fclose(fp);

	return head;
}

void print_list(node* head){
	printf("\nThe linked list : \n");

	while(head != NULL){
		printf("%s --->", head->word);
		head = head->next;
	}
	printf("NULL\n");
}

void delete(node* head){
	node* current = head;
	node* next;
	
	//traverse linked list and free allocated space
	while(current!=NULL){
		next = current->next;
		free(current->word);
		free(current);
		current = next;
	}
}

