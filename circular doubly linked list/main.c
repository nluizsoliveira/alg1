#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<game.h>
#include<catalog.h>

int main (){
    char csv_filepath[10]= "CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    char ghost_byte;

    fscanf(csv,"%c", &ghost_byte);
    fscanf(csv,"%c", &ghost_byte);
    fscanf(csv,"%c", &ghost_byte);
    
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
            name = (char*) malloc(sizeof(char) * strlen(line));
            year = (char*) malloc(sizeof(char) *strlen(line));
            company = (char*) malloc(sizeof(char) *strlen(line));

            sscanf(line, "%[^;]s%[^;]s%[^;]s", name, year, company);
            Game* game = new_Game(name, year, company);
            add_Game_to_Catalog(game, catalog);
        }
    }
    print_Catalog(catalog);
    fclose(csv);
    return 0;
}

