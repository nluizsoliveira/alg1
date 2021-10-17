#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<game.h>

int main (){
    char csv_filepath[10]= "./CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    char* line;
    int is_line_valid = true;
    char* name;
    char* year;
    char* company;
    

    while(is_line_valid){
        line = read_line_from_file(csv);
        is_line_valid = strlen(line);

        if(is_line_valid){
            char* split = strtok(line, ";");
            name = (char*) malloc(sizeof(char) * strlen(split));
            strcpy(name, split);

            split = strtok(NULL, ";");
            year =  (char*) malloc(sizeof(char) * strlen(split));
            strcpy(year, split);
    
            split = strtok(NULL, ";");
            company = (char*) malloc(sizeof(char) * strlen(split));
            strcpy(company, split);

            Game* game = new_Game(name, year, company);
            printf("[%s][%s][%s]\n", game->name, game->year, game->company);
        }
    }
    printf("saiu\n");
    fclose(csv);
    return 0;
}

