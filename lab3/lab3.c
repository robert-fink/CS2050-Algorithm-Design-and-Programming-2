//Robert Fink
//rwfwcb
//Lab3
//Labcode: Stuff & Things

#include <stdlib.h>
#include <stdio.h>
#define MAX_STRING_LEN 20

typedef struct account{
	int accountId;
	char* name;
	double amount;
	}Account;
	
Account* load_accounts(char* inputFile, int* size);
Account* find_account(Account* account, int size, int accountId);
void update_accounts(char* updateFile, Account* account, int size);
void write_accounts(char* outputFile, Account* account, int size);
void free_accounts(Account* account, int size);

int main(int argc, char* argv[]){
	if(argc !=4){
		printf("Insufficient arguments\n");
		return -1;
	}
	
	//initialize variables
	int size;
	
	Account* account = load_accounts(argv[1], &size);
		if(account == NULL) return -1;
	
	update_accounts(argv[2], account, size);
	write_accounts(argv[3], account, size);
	free_accounts(account, size);
	
	return 0;
}

Account* load_accounts(char* inputFile, int* size){
	//initialize variables
	int i=0;
	
	//initialize file pointer and open file
	FILE* file = fopen(inputFile, "r");
	
	//read the first line containing size value
	fscanf(file, "%d", size);
	
	//malloc for a structure array
	Account* account = NULL;
	account = malloc((*size) * sizeof(Account));
	
	//for loop to read into array
	for(i=0; i<(*size); ++i){
		account[i].name = malloc(sizeof(char) * MAX_STRING_LEN);
		fscanf(file, "%d %s %lf", &account[i].accountId, account[i].name, &account[i].amount);
		}
	
	//close file pointer
	fclose(file);
	return account;
}

Account* find_account(Account* account, int size, int accountId){
	//initialize variables
	int i=0;
	
	//loop to find account from given accountId, NULL if not found
	for(i=0; i<size; ++i){
		if(accountId == account[i].accountId){
			return &account[i];
		}
	}
	return NULL;
}

void update_accounts(char* updateFile, Account* account, int size){
	//initialize variables
	int i=0, tempId=0;
	double transaction=0;
	Account* tempAccount;
	int length =0;
	FILE* file2 = fopen(updateFile, "r");
	//if(file2==NULL) return NULL;
	
	//scan in size
	fscanf(file2, "%d", &length);
	
	//loop to scan in ID and transaction, check for ID - then do transaction
	for(i=0; i<length; ++i){
		fscanf(file2, "%d %lf", &tempId, &transaction);
		tempAccount = find_account(account, size, tempId);
			if(tempAccount!=NULL){
				tempAccount->amount += transaction;
			}
		}
	
	//close file pointer
	fclose(file2);	
}

void write_accounts(char* outputFile, Account* account, int size){
	//initialize variables
	int i=0;
	FILE* file3 = fopen(outputFile, "w");
	
	//loop to print outputFile
	for(i=0; i<size; ++i){
		fprintf(file3, "%d %s %lf\n", account[i].accountId, account[i].name, account[i].amount);
	}
	//close file pointer
	fclose(file3);
}

void free_accounts(Account* account, int size){
	//initialize variables
	int i=0;
	//free all allocated memory
	for(i=0; i<size; ++i){
		free(account[i].name);
		}
	free(account);
}

