#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<game.h>
#include<catalog.h>

int main (){
    char csv_filepath[10]= "./CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    char* line;
    int is_line_valid = true;
    char* name;
    char* year;
    char* company;
    
    Catalog* catalog = new_Catalog();

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
            add_Game_to_Catalog(game, catalog);
        }
    }
    print_Catalog(catalog);
    fclose(csv);
    return 0;
}

