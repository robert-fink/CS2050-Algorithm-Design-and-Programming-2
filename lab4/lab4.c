//name: Robert Fink
//pawprint: rwfwcb
//lab code:

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //added header

#define MAX_ACCOUNTS 20
#define MAX_STR_LEN 20

typedef struct {
    //int accountId
    int accountId; //added missing ";""
	char* name;
    float balance;
} Account;

int load_accounts(Account accounts[], char* fileName);
Account* find_account(Account accounts[], int len, int id); //added function prototype
void run_transactions(Account accounts[], int length, char* fileName);
void sort(Account accounts[], int length);
void print(Account accounts[], int length);
void free_accounts(Account accounts[], int length);

int main(int argc, char* argv[]) { 
    
	//if (argc != 2) {
    if (argc !=3){  //correction
        printf("Incorrect number of command line arguments\n");
        printf("Correct usage: %s <account list> <transactions>\n", argv[0]);
    }

  

    //Account* accounts = malloc(sizef(Account) * MAX_ACCOUNTS);
    Account* accounts = malloc(sizeof(Account) * MAX_ACCOUNTS);

	//len = load_accounts(accounts, argv[1]);
    int len = load_accounts(accounts, argv[1]); //corrected to type 'int'
	sort(accounts, len);
 
    run_transactions(accounts, len, argv[2]);
    print(accounts, len);

	free_accounts(accounts, len);
	
    return 0;
}


int load_accounts(Account accounts[], char* fileName) {
    
    FILE* fp = fopen(fileName, "r");
    
    if (fp == NULL) {
        return 0;
    }

    int id;
    float balance;
	char name[MAX_STR_LEN];
	
    int len = 0;

    while (len <= MAX_ACCOUNTS) {
		//fscanf(fp, "%d %s %f", &id, &name, &balance);
        fscanf(fp, "%d %s %f", &id, name, &balance);    //removed & operator
        accounts[len].name = malloc(sizeof(char) * MAX_STR_LEN);    //added malloc

        if (feof(fp)) { 
            break;
        }

        accounts[len].accountId = id;
        accounts[len].balance = balance;
        //accounts[len] = name;
        strcpy(accounts[len].name, name);
		
        len++;
    }


    return len;
}

Account* find_account(Account accounts[], int len, int id) {
    
	int i = 0; 
	
	//for (i = 0; i < len; i++); {
    for(i=0; i< len; i++){  //removed ";"
		//if (accounts[i] == id) {
        if (accounts[i].accountId == id){   //added . operator
			return &accounts[i];
		}
	
	//return NULL;
}
    return NULL; //moved line here
} //added missing close bracket

void run_transactions(Account accounts[], int length, char* fileName) {
    
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL) { 
        return;
    }

    int id;
    float balance;

    while (1) {
        fscanf(fp, "%d %f", &id, &balance);
        if (feof(fp)) {
            break;
        }

        //Account* account = find_account(accounts, 0, length -1, id);
        Account* account = find_account(accounts, length, id); //removed extra argument and fixed length

        if (account == NULL) {
            printf("Invalid transaction; account %d does not exist\n", id);
        //} else if (account.balance + balance < 0) {
        } else if (account->balance + balance < 0) { //corrected pointer notation
  			printf("Invalid transaction; Withdrawing $%0.2f from account %d results in a negative balance\n", balance, id);
        } else {
            account->balance += balance;
        }
    }

} 
//} removed extra bracket

void sort(Account accounts[], int length) {
    //int i, j, k;
    int i, j; //removed unused variable k

    for (i = 0; i < length; ++i) {
		for (j = 0; j < length - 1; ++j) {
            if (accounts[j].accountId > accounts[j+1].accountId) {
                Account account = accounts[j];
                accounts[j] = accounts[j+1];
                accounts[j+1] = account;
            }
        }
    }
}

void print(Account accounts[], int length) {
    //int i, j; 
    int i; //removed unused variable j
    
    printf("\nFinal balance sheet\n");
    for (i = 0; i < length; ++i) {
        //printf("%d %.2f\n", accounts[i].accountId, accounts[i].balance);
        printf("%d %s %.2f\n", accounts[i].accountId, accounts[i].name, accounts[i].balance);
    }
}

void free_accounts(Account accounts[], int length) {
	
	int i;
	for (i = 0; i < length; i++) {
		//free(accounts[i]);
        free(accounts[i].name);
	}
	
	free(accounts);
}