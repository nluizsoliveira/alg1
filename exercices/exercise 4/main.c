#include <stdio.h>
#include <readline.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<numbers.h>

int main (){
    int operations_amount;
    scanf("%d ", &operations_amount);
    for(int position = 0; position < operations_amount; position++){
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
        

        if (strcmp(operation, "soma") == 0 ){
            get_soma(first_number, second_number);
        }

        else if (strcmp(operation, "maior") == 0 ) {
            bool isBigger = isNumberBiggerThanNumber(first_number, second_number);
            printNumbersComparison(isBigger);
        }
        else if (strcmp(operation, "menor") == 0 ) {
            bool isSmaller = ! isNumberBiggerThanNumber(first_number, second_number);
            printNumbersComparison(isSmaller);
        }
        else if(strcmp(operation, "igual") == 0 ){
            bool areEqual = areNumbersEqual(first_number, second_number);
            printNumbersComparison(areEqual);
        }
    } 

    return 0;
}

