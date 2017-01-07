//Robert Fink
//rwfwcb
//cs2050
//Homework4

#include "analysis.h"

int main(int argc, char* argv[]){
	if (argc != 7){
		printf("Error: exactly 7 arguments required\n");
		printf("Format: ./a.out positive_words negative_words review1 review2 review3 review4\n");
		return -1;
	}
	
	//initialize variables
	node* positive_words = NULL;
	node* negative_words = NULL;

	//create linked lists
	positive_words = create_list(argv[1]);
	negative_words = create_list(argv[2]);

	//perform sentiment_analysis on reviews
	sentiment_analysis(argv[3], negative_words, positive_words);
	sentiment_analysis(argv[4], negative_words, positive_words);
	sentiment_analysis(argv[5], negative_words, positive_words);
	sentiment_analysis(argv[6], negative_words, positive_words);
	
	//free
	delete(positive_words);
	delete(negative_words);

	return 0;
}