#include<stdio.h>
#include<readline.h>

int main(){
    char* input_test_string = read_line(stdin);
    printf("%s", input_test_string);

    FILE* file = fopen("test.in", "r");
    char* file_test_string = read_line(file);
    printf("\n%s", file_test_string);
    
    return 0;
}