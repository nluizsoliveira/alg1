#include <stdio.h>
#include <readline.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>


typedef struct digit{
    char value;
    struct digit* next;
} Digit;

Digit* new_Digit(char value) {
    Digit* digit = (Digit*) malloc(sizeof(Digit));
    digit->next = NULL;
    digit->value = value;

    return digit;
}

typedef struct Number {
    bool isPositive;
    int size;
    Digit* leastSignificantDigit;
} Number;

Number* new_Number(bool isPositive) {
    Number* number = (Number*) malloc(sizeof(Number));
    number->isPositive = true;
    number->size = 0;
    number->leastSignificantDigit = NULL;

    return number;
}

void* add_Digit_to_Number(Digit* digit, Number* number){
    number->size +=1;
    digit->next = number->leastSignificantDigit;
    number->leastSignificantDigit = digit;
}

void* print_Number(Number* number) {
    Digit* current_digit = number->leastSignificantDigit;
    while(current_digit != NULL){
        printf("%d", current_digit->value);
        current_digit = current_digit->next;
    }
}

int main (){
    int operations_amount;
    scanf("%d ", &operations_amount);
    for(int counter = 0; counter < operations_amount; counter++){
        char* operation;
        char* first_number_buffer;
        char* second_number_buffer;

        char* line = read_line();
        char *line_split = strtok(line,  " ");

        operation = (char *) malloc(strlen(line_split) * sizeof(char));
        strcpy(operation, line_split);

        line_split = strtok(NULL, " ");
        first_number_buffer = (char *) malloc(strlen(line_split) * sizeof(char));
        strcpy(first_number_buffer, line_split);

        line_split = strtok(NULL, " ");
        second_number_buffer = (char *) malloc(strlen(line_split) * sizeof(char));
        strcpy(second_number_buffer, line_split);

        printf("%s %s %s\n", line,first_number_buffer,second_number_buffer);
        
        Number* number = new_Number(true);


        Digit* seven = new_Digit(7);
        Digit* eight = new_Digit(8);

        add_Digit_to_Number(seven, number);
        add_Digit_to_Number(eight, number);

        print_Number(number);
        return 0;
        

        //char carry = (a->value+b->value)/10;
        //char mod = (a->value+b->value)%10;


        //printf("%d %d %d %d\n", a->value,b->value, carry, mod);
    }

}

