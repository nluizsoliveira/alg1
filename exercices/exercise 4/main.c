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
        
        Digit* a = new_Digit(7);
        Digit* b = new_Digit(7);

        char carry = (a->value+b->value)/10;
        char mod = (a->value+b->value)%10;


        printf("%d %d %d %d\n", a->value,b->value, carry, mod);
    }

}

