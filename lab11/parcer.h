#ifndef PARCER_H
#define PARCER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 250

int is_phone_number(char* word);
int is_date(char* word);
int looks_like_name(const char* word);
int is_email(char* word);

#endif