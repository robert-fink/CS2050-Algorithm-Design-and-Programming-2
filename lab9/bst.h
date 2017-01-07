#ifndef bst_h
#define bst_h

//Robert Fink
//cs2050
//lab9

#include <stdlib.h>
#include <stdio.h>

typedef struct node_{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
void inorder(BST* tree);
void destroy(BST* tree);

#endif