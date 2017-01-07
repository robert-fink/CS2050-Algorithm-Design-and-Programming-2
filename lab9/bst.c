//Robert Fink
//cs2050
//lab9

#include "bst.h"

BST* insert(BST* tree, int data){
	if (tree == NULL){
		tree = (BST*) malloc(sizeof(BST));
		tree->data = data;
		tree->left = tree->right = NULL;
		return tree;
	}
	
	else if (data <= tree->data){
		tree->left = insert(tree->left, data);
	}
	
	else if (data > tree->data){
		tree->right = insert(tree->right, data);
	}
	
	return tree;
}

void inorder(BST* tree){
	if (tree != NULL){
		inorder(tree->left);
		printf("%d ", tree->data);
		inorder(tree->right);
	}
}

void destroy(BST* tree){
	if (tree == NULL)
		return ;
	
	destroy(tree->left);
	destroy(tree->right);
	free(tree);
}

BST* find(BST* tree, int data){
	//base case: null
	if (tree == NULL || tree->data == data)
		return tree;
	
	//data value is greater than tree root
	if (tree->data < data)
		return find(tree->right, data);
		
	//data value is less than the tree root
	else
		return find(tree->left, data);		
}


