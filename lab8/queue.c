#include <stdlib.h>
#include "queue.h"

void enqueue(queue** head, char* name){
	queue *temp, *current, *rear=(*head);

	current = (queue*)malloc(sizeof(queue));

	current->name = name;
	current->next = NULL;
	
	
	if(*head == NULL){
		*head = rear = current;
	}
	
	
	else{
		while(rear->next != NULL){
			rear = rear->next;
		}
		
		rear->next = current;
	
	}
}

char* dequeue(queue** head){
	queue *temp, *rear;
	char* name = NULL;
	
	temp = *head;
	name = temp->name;
	temp = temp->next;
	free(*head);
	*head = temp;
	
	return name;
}

void free_queue(queue* head){
	queue* current = head;
	queue* next;
	
	while(current!=NULL){
		next = current->next;
		free(current);
		current = next;
	}
}