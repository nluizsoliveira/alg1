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

        // printf("%s [%c] %s [%c] %s\n", line, first_number_buffer[0], first_number_buffer, second_number_buffer[0],second_number_buffer);

        bool is_first_number_negative  = (first_number_buffer[0] == '-');
        Number* first_number = new_Number(is_first_number_negative);
        int position = 0;
        int size = strlen(first_number_buffer);
        
        if(is_first_number_negative){
            position = 1; 
        }

        for(position; position < size; position ++ ){
            int value = first_number_buffer[position] - '0';
            Digit* digit = new_Digit(value);
            add_Digit_to_Number(digit, first_number);
        }


        bool is_second_number_negative  = (second_number_buffer[0] == '-');
        Number* second_number = new_Number(is_second_number_negative);
        position = 0;
        size = strlen(second_number_buffer);

        if(is_second_number_negative){
            position = 1;
        }

        for(position; position < size; position ++ ){
            int value = second_number_buffer[position] - '0';
            Digit* digit = new_Digit(value);
            add_Digit_to_Number(digit, second_number);
        }

        print_Number(first_number);
        printf("\n");
        print_Number(second_number);
        return 0;
        

        //char carry = (a->value+b->value)/10;
        //char mod = (a->value+b->value)%10;


        //printf("%d %d %d %d\n", a->value,b->value, carry, mod);
    }

}

