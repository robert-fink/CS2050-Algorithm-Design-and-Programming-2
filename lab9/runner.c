//Robert Fink
//cs2050
//lab9
//labcode: LEGO

#include "bst.h"

int main(int argc, char* argv[]){
	//initialize variables
	BST* temp = NULL;
	BST* root = NULL;
	int value = 0;
	int num = 0;
	
	FILE* fp = fopen(argv[1], "r");
		if (fp == NULL){
			puts("Error: unable to open input file");
			return -1;
		}
	
	while (1){		
		fscanf(fp, "%d", &value);
	
		if (feof(fp)){
			break;
		}
		
		root = insert(root, value);
	}
	
	inorder(root);
	
	num = atoi(argv[2]);
	temp = find(root, num);
	
	if (temp == NULL)
		printf("\n%d was not found\n", num);
	else
		printf("\n%d was found", num);
	
	destroy(root);
	
	return 1;
}