#include <stdio.h>
#include <readline.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct digit{
    char value;
    struct digit* next;
} Digit;

Digit* new_Digit(int value) {
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

Number* get_Number_from_buffer(char* buffer){
    bool is_number_negative  = (buffer[0] == '-');
    Number* number = new_Number(is_number_negative);
    int position = 0;
    int size = strlen(buffer);
    
    if(is_number_negative){
        position = 1; 
    }

    for(position; position < size; position ++ ){
        int value = buffer[position] - '0';
        Digit* digit = new_Digit(value);
        add_Digit_to_Number(digit, number);
    }

    return number;
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

        Number* first_number = get_Number_from_buffer(first_number_buffer);
        Number* second_number = get_Number_from_buffer(second_number_buffer);

        print_Number(first_number);
        printf("\n");
        print_Number(second_number);
        return 0;
        

        //char carry = (a->value+b->value)/10;
        //char mod = (a->value+b->value)%10;


        //printf("%d %d %d %d\n", a->value,b->value, carry, mod);
    }

}

