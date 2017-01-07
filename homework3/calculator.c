//Robert Fink
//homework3
//cs2050

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

/*
 * Returns a number corresponding the the preccedence 
 * of different arithmetic operators. * has a higher 
 * precedence that / which is greater than %, +, -
 * in that order. Higher precedence should return a higher
 * number so say 5 for * 1 for - and 0 for a non operator
 */
static int prec(char operator) {
	switch(operator){
		case '*':
			return 5;

		case '/':
			return 4;

		case '%':
			return 3;

		case '+':
			return 2;

		case '-':
			return 1;

		case '(':
			return 0;
	}
}

/*
 * Returns 1 if the string passed is an inteter
 * 0 otherwise
 */
static int isNumeric(char *num) {
	if (isdigit(atoi(num))){
		return 1;
	}
	else
		return 0;
}

/*
 * converts a valid infix expression into postfix
 * Hint put a space between numbers and operators 
 * so you can use strtok in evaluate_postfix
 * ex: get 7 8 + vs 78+
 *
 * This is done with the following algorithm
 *
 * for each token in the string
 *     if the next token is a number
 *         append it to the postfix string
 *     else if the next token is a left paren
 *          push it onto the stack
 *     else if the next token is a right paren
 *          while the stack is not empty and the left paren is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 *          pop the left paren off of the stack and discard it
 *     else if the next token is an operator (+, -, *, /)
 *         while the stack is not empty and the operator at the top of the stack has a higher precedence than the token
 *              pop the top element off of the stack and append it to the postfix string
 *         push the current token onto the stack
 *
 * while there are elements remaining on the stack
 *     pop the top element off of the stack and append it to the postfix string
 */
char* infix_to_postfix(char* infix) {
	//initialize variables
	//char postfix[];
	char *postfix = malloc(sizeof(char) * MAX_EQU_LEN);
	int i=0, j=0, x;
	//char token;
	//char *delim = " \n";

	stack *s = create_stack();
	
	while (infix[i] != '\0'){
		if (isNumeric(&infix[i])){
			postfix[j++] = infix[i];
			postfix[j++] = ' ';
		}
		else if (infix[i] == '('){
			push(s, '(');
		}
		else if (infix[i] == ')'){
			while (x=top(s) != '('){
				postfix[j++] = x;
				postfix[j++] = ' ';
				pop(s);
			}
		}
		else{
			while(prec(infix[i]) <= prec(top(s)) && !isEmpty(s)){
				x = top(s);
				pop(s);
				postfix[j++] = x;
				postfix[j++] = ' ';
			}
		}
		push(s, infix[i]);	
		i++;
	}

	while (!isEmpty(s)){
		x = top(s);
		postfix[j++] = x;
	}
	
	printf("%s", postfix);
	
	free(s);
	
	return postfix;
}

/*
 * This function takes in a valid postfix expression
 * and evaluate it to an integer
 *
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top 2 element off of the stack
 *          the first goes into the right variable
 *          the second goes into the left variable
 *          apply the operation: 
 *              result = left op right
 *              ex result = left + right
 *
 *          push the result onto the stack
 *          
 * return the result from the stack
 */

int evaluate_postfix(char* postfix) {
	char *token;
	char *delim = " ";
	int result, x, var1, var2;
	
	stack *s = create_stack();
	
	token = strtok(postfix, delim);
	
	while(token != NULL){
		if (isNumeric(token)){	//push operand
			x = atoi(token);
			push(s, x);
		}
		else{	//operator, pop 2 operands
			var2 = top(s);
			pop(s);
			var1 = top(s);
			pop(s);
						
			switch(token[0]){
				case '+':
					result = var1 + var2;
					break;
					
				case '-':
					result = var1 - var2;
					break;
				case '*':
					result = var1 * var2;
					break;
				case '/':
					result = var1 / var2;
					break;
				case '%':
					result = var1 % var2;
					break;
			}
			push(s, result);
		}
		token = strtok(NULL, delim);
	}
	result = top(s);
	pop(s);
	free(s);
	return top(s);
}

