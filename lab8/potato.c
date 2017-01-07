//Robert Fink
//cs2050 lab8
//lab code: enqueue

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* load_queue(char*);
queue* play_game(int, queue*);

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Incorrect number of command line arguments (requires 2) \n");
		return -1;
	}
	
	//initialize variables
	queue *head = NULL;
	int passes = 0;
	
	head = load_queue(argv[1]);
	
	puts("Enter the number of passes or -1 to quit");
	scanf("%d", &passes);
	
	head = play_game(passes, head);
	
	free_queue(head);
	
	return 1;
}

queue* load_queue(char* input){
	//initialize variables
	char* name = NULL;
	queue *head = NULL;

	FILE* fp = fopen(input, "r");
	
	if(fp==NULL)
		puts("Error: unable to open the file");
	
	while(1){
		name = malloc(sizeof(char) * 20);
		fscanf(fp, "%s", name);
		if(feof(fp)){
			break;
		}
		enqueue(&head, name);
	}
	fclose(fp);
	
	return head;
}

queue* play_game(int passes, queue* head){
	//initialize variables
	int i=0;
	char* holder;
	
	for(i=0; i<passes; ++i){
		holder = dequeue(&head);
		
		if (i == passes-1){
			printf("%s got the potato and lost \n", holder);
			break;
		}
		
		else{
			printf("%s got the potato and passed to \n", holder);
			enqueue(&head, holder);
		}
	}
	return head;
}
		

		

