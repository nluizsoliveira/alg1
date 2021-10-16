#include<stdbool.h>

#ifndef _numbers_
#define _numbers_

typedef struct digit{
    char value;
    struct digit* next;
} Digit;

typedef struct Number {
    bool isPositive;
    int size;
    Digit* leastSignificantDigit;
} Number;


Digit* new_Digit(int value);
Number* new_Number(bool isNegative);
void* add_Digit_to_Number(Digit* digit, Number* number);
void* print_Number(Number* number);
Number* get_Number_from_buffer(char* buffer);
bool areNumbersEqual(Number* A, Number* B);
bool isNumberBiggerThanNumber(Number* A, Number* B);
void printNumbersComparison(bool isComparison);
void printSoma(Number* number);
void get_soma(Number*first_number, Number* second_number);

#endif
