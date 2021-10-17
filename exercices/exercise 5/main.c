#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>

int main (){
    char csv_filepath[10]= "./CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    int counter = 1;
    char* line = read_line_from_file(csv);
    printf("%d %s\n", counter, line);

    while(strlen(line)){
        line = read_line_from_file(csv);
        counter++;
        printf("%d: %s\n", counter, line);
    }
    fclose(csv);
    return 0;
}
