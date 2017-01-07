//Robert Fink
//rwfwcb
//cs2050
//Homework4

#ifndef analysis_h
#define analysis_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
	char *word;
	struct node_ *next;
}node;

void sentiment_analysis(char*, node*, node*);
int is_positive(char*, node*);
int is_negative(char*, node*);
node* create_list(char*);
node* insert_at_head(node*, char*);
void print_list(node*);
void delete(node*);

#endif

