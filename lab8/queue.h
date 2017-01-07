//#ifndef queue.h
#define queue_h

typedef struct node_{
	char* name;
	struct node_ *next;
	}queue;
	
void enqueue(queue** head, char* name);
char* dequeue(queue** head);
void free_queue(queue* head);