#include <stdio.h>
#include<readline.h>


int main (){
    int operations_amount;
    scanf("%d ", &operations_amount);
    for(int line_counter = 0; line_counter < operations_amount; line_counter++){
        char* line = read_line();
        printf("%s\n", line);
    }


}