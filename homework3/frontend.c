//Robert Fink
//homework3
//cs2050

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define BUFFERSIZE 100

int main(int argc, char* argv[]) {
    
    char buffer[BUFFERSIZE];
    if (argc != 2) {
        printf("correct ussage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("unable to open file: %s\n", argv[1]);
        return 1;
    }

    while(fgets(buffer, BUFFERSIZE, fp)) {
        if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0'; 
        }
        char *postfix = infix_to_postfix(buffer);
        int result = evaluate_postfix(postfix);
        printf("%s = %d\n", buffer, result);
		free(postfix);
    }

    fclose(fp);
    
    return 0;
}
