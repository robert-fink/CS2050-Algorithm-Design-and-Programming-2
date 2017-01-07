//Robert Fink
//rwfwcb
//cs2050
//lab10
//labcode: SPACE


#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int data;
    struct node_ *left;
    struct node_ *right;
} BST;

void structure(BST* root, int level);
void padding(char ch, int n);
BST* build_balanced_tree(int a[], int low, int high); 
BST* min(BST* tree);
BST* delete_node(BST* tree, int data);
void mirror(BST* tree);

/**
 * param a: an int array
 * param low: the lowest valid indice in the array
 * param high: the highest valid indice in the array
 *
 * return: the root of a balanced BST
 *
 * This function should build a balanced bst from a sorted array. 
 * Hint: This function should look similar to binary search. 
 */
BST* build_balanced_tree(int a[], int low, int high){
    int mid;
    BST* temp = (BST*)malloc(sizeof(BST));

    if (low > high)
        return NULL;

    mid = (low + high) / 2;
	
    temp->data = a[mid];
    temp->left = build_balanced_tree(a, low, mid-1);
    temp->right = build_balanced_tree(a, mid+1, high);
    return temp;
}

BST* min(BST* tree){	//This function returns the smallest value in a BST 
	BST *current = tree;
	
	//loop down to find leftmost leaf
	while (current->left != NULL)
		current = current->left;
		
	return current;
}

BST* delete_node(BST* tree, int data){	//this function deletes a specified node from a BST
	//base case
	if (tree == NULL) return tree;
	
	//if data is smaller than tree root, it lies in left half of tree
	if (data < tree->data)
		tree->left = delete_node(tree->left, data);
		
	//if data is greater than tree root, it lies in right half of tree
	else if (data > tree->data)
		tree->right = delete_node(tree->right, data);
	
	//if data equals tree->data than this is the correct node to delete_node
	else{
		//node has either 1 or no children
		if (tree->left == NULL){
			BST *temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL){
			BST *temp = tree->left;
			free(tree);
			return temp;
		}
		//node has 2 children: get the inorder successor (smallest node in right subtree)
		BST *temp = min(tree->right);
		
		//copy inorder successor's data to this node
		tree->data = temp->data;
		
		//delete inorder successor
		tree->right = delete_node(tree->right, temp->data);
	}
	return tree;
}

void mirror(BST* tree){
	if (tree == NULL)
		return;
	else{
		BST *temp;
		
		mirror(tree->left);
		mirror(tree->right);
		
		temp = tree->left;
		tree->left = tree->right;
		tree->right = temp;
	}
}
    
void padding(char ch, int n) {
    int i;

    for (i = 0; i < n; ++i) {
        putchar(ch);
    }
}

void structure(BST* root, int level) {
    if (root == NULL) {
        padding('\t', level);
        puts("~");
    } else {
        structure(root->right, level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        structure(root->left, level+1);
    }
}

int main(int argc, char* argv[]) {
	//initialize variables
	int i=0, size=0, val=0;
	
	if (argc != 2){
		printf("Incorrect number of command line arguments: requires 2\n");
		return -1;
	}
	
	//create file pointer and open file from command line arguments
    FILE* fp = fopen(argv[1], "r");
	
	//scan in size from input file
	fscanf(fp, "%d", &size);
	
	//initialize array
	int a[size];
	
	//place values into array
	for (i=0; i<size; ++i){
		fscanf(fp, "%d", &val);
		a[i] = val;
	}
	
	//build a balanced binary search tree
    BST* root = build_balanced_tree(a, 0, size-1);
	
	//print binary search tree
	puts("Tree");
    structure(root, 0);
	
	//ask user for input
	printf("Enter a number to delete: ");
	scanf("%d", &val);
	
	//delete specified node
	root = delete_node(root, val);
	
	//print binary search tree w/o val
	printf("Tree without %d\n", val);
	structure(root, 0);
	
	//print binary search tree w/ bonus
	printf("Bonus\n");
	mirror(root);
	structure(root, 0);
	
	//close file pointer
	fclose(fp);

    return 0;
}