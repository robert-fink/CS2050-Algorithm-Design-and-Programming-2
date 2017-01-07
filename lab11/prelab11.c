#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/**
 * Param string: a string
 *
 * Return: 1 if the string is a phone number, 0 otherwise
 *
 * A phone number takes the form (xxx)-xxx-xxxx where the 
 * x's are digits 0-9.
 */
int is_phone(char* string);

int main(void) {
    assert(is_phone("(123)-456-7890") == 1);
    assert(is_phone("(123) 456-7890") == 0);
    assert(is_phone("123-456-7890") == 0);
    assert(is_phone("(123)-45e-7890") == 0);
    assert(is_phone("(123)-456-789") == 0);

    printf("Yay!!\n");

    return 0;
}

int is_phone(char* word){
	//initialize variables
	int i=0;
	
	if (strlen(word) != 14) return 0;
	
	if (word[0] != ('(')) return 0;
	
	for(i=1; i<=3; ++i){
		if (isdigit(word[i]) == 0) return 0;
	}
	
	if (word[4] != (')')) return 0;
	if (word[5] != ('-')) return 0;

	for(i=6; i<=8; ++i){
		if (isdigit(word[i]) == 0) return 0;
	}
	
	if (word[9] != ('-')) return 0;

	for(i=10; i<=13; ++i){
		if (isdigit(word[i]) == 0) return 0;
	}
	return 1;
}