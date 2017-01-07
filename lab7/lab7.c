//Robert Fink
//labcode: I don't know
//cs2050

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
	int val;
	struct node_ *next;
}node;
node* create_list(char* file);
node* insert_at_head(node* head, int val);
void print_list(node* head);
node* delete_even(node* head);
void delete(node* head);
node* reverse_list(node* head);

int main(int argc, char* argv[]){
	//initialize variables
	node *head = NULL;
	node *reverse_head = NULL;
	
	head = create_list(argv[1]);
	
	print_list(head);
	
	head = delete_even(head);
	
	print_list(head);
	
	reverse_head = reverse_list(head);
	
	print_list(reverse_head);
	
	delete(head);

	return 1;
}

node* reverse_list(node* head){
	node* rest = head->next;
	node* temp = NULL;
	
	if(head==NULL)
		return head; //empty list
	
	if(rest==NULL)
		return head; //one node in list
	
	
	temp = reverse_list(rest);
	head->next->next = head;
	head->next = NULL;
	head = rest;
	
	return temp;
}

node* delete_even(node* head){
	//initialize variables
	node* temp = NULL;
	node* prev = head;
	node* current = head->next;
	//node* i;
	
	while(head->val %2 == 0){	//if first value in linked list is even, remove the first link in the list
		temp = head;
		head = head->next;
		free(temp);
	}
	
	for(current = head; current!=NULL; current = current->next){
		if(current->val %2 == 0){	//if data is an even number
			//change next link of previous node
			prev->next = current->next;
			temp = current;
			free(temp);
		}
		//update previous and current
		prev = prev->next;
		current = current->next;
	}
	return head;
}

void delete(node* head){
	node* current = head;
	node* next;
	
	while(current!=NULL){
		next = current->next;
		free(current);
		current = next;
	}
}
	
node* insert_at_head(node* head, int val){

	node *new_node;

	new_node = (node*)malloc(sizeof(node));

	new_node->val = val;
	new_node->next = head;

	return new_node;
}

node* create_list(char* file){
	//initialize variables
	int val=0;	
	node *head = NULL;

	FILE* fp = fopen(file, "r");
	
	if(fp==NULL)
		puts("Error: unable to open the file");
	
	while(1){
		fscanf(fp, "%d", &val);
		head = insert_at_head(head, val);
		if(feof(fp)){
			break;
		}
	}
		return head;
}

void print_list(node* head){
	printf("\nThe linked list : \n");

	while(head != NULL){
		printf("%d--->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}
