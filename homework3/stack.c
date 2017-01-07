//Robert Fink
//homework3
//cs2050

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* 
 * Creates an empty stack and sets
 * the size equal to 0
 */

stack* create_stack() {
	stack *s = (stack*) malloc(sizeof(stack));
	s->size = 0;
	//s->stack = NULL;
	return s;
}

/*
 * pushes the value into the top of the stack
 */ 
void push(stack *s, int val) {

	node *new = (node*) malloc(sizeof(node));	//malloc a node
	if (new == NULL)
		printf("\nMemory cannot be allocated\n");
	
	new->data = val; 	//set the data of the node
	new->next = s->stack;	//node->next is going to point to the stack
	s->stack = new;		//s->stack points to the node
	s->size++;	//increment stacks size
}

/*
 * pops the head of the stack
 * the value is not returned
 */
void pop(stack *s) {
	if (s->stack == NULL)
		return;
	node *temp;
	temp = s->stack;
	s->stack = temp->next;
	free(temp);
	s->size--;
}


/*
 * returns the value at the top of the stack
 * the stack remains unchanged
 */
int top(stack *s) {
	if (isEmpty(s)){
		return -1;
	}
	else
		return s->stack->data;
}

/*
 * returns 1 if the stack is empty
 * 0 otherwise
 */
int isEmpty(stack *s) {
	if (s == NULL){
		return 1;
	}
	else
		return 0;
}


