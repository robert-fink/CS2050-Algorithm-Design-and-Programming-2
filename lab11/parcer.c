//Robert Fink
//lab11

#include "parcer.h"

int is_phone_number(char* word){
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

int is_date(char* word){
	//initialize variables
	int i=0, day, month, year;
	int validDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
	
	if (strlen(word) != 10) return 0;
	if (word[2] != '/') return 0;
	if (word[5] != '/') return 0;
	
	word[2] = '\0';
	word[5] = '\0';
	
	month = atoi(word);
	day = atoi(&word[3]);
	year = atoi(&word[5]);
	
	if (isdigit(month)<1  ||  isdigit(month)>12) return 0;
	
	if (isdigit(day)<0 || isdigit(day) > validDays[month-1]) return 0;
	
	if (isdigit(year) == 0) return 0;
	
	return 1;
	
}

int looks_like_name(const char* word){
	//initialize variables
	int i=0, size=0;
	
	size = strlen(word);
	
	for (i=0; i<size; ++i){
		if (isalpha(word[i]) == 0) return 0;
	}
	
	if (islower(word[0])) return 0;

	for (i=1; i<size; ++i){
		if(isupper(word[i])) return 0;
	}
	
	return 1;
}

int is_email(char* word){
	//initialize variables
	int i=0, size=0;
	
	size = strlen(word);
	
	for (i=0; i<size; ++i){
		if (isalnum(word[i]) == 0){
			if (word[i] == '@') continue;
			if (word[i] == '.') continue;
			if (word[i] == 'c') continue;
			if (word[i] == 'o') continue;
			if (word[i] == 'm') continue;
			
			else return 0;
		}
	}
	return 1;
	}