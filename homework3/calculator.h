#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"

char* infix_to_postfix(char* equ);
int evaluate_postfix(char* equ);
static int prec(char operator);
static int isNumeric(char *num);


#endif
