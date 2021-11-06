//Tarabalho feito em dupla por Nelson 9793502 e Alexandre 11857323
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

    char header_byte;

    fscanf(csv,"%c", &header_byte);
    fscanf(csv,"%c", &header_byte);
    fscanf(csv,"%c", &header_byte);
    
    char* line;
    int is_line_valid = true;
    char* name;
    char* year;
    char* company;
    char PARSE_MASK[20];
    
    Catalog* catalog = new_Catalog();

    while(is_line_valid){
        line = read_line_from_file(csv);
        is_line_valid = strlen(line);

        if(is_line_valid){
            name = (char*) malloc(sizeof(char) * strlen(line));
            year = (char*) malloc(sizeof(char) *strlen(line));
            company = (char*) malloc(sizeof(char) *strlen(line));

            strcpy(PARSE_MASK, "%[^;];%[^;];%[^;]");
            sscanf(line, PARSE_MASK, name, year, company);

            Game* game = new_Game(name, year, company);
            add_Game_to_Catalog(game, catalog);
        }
    }

    int is_there_input = true;

    while (is_there_input) {
        char PRINT_CATALOG = 'i';
        char PRINT_CATALOG_BY_COMPANY = 'p';
        char REMOVE_DUPLICATED_GAMES = 'r';
        char PRINT_CATALOG_BY_YEAR = 'a';
        char FREE = 'f';
        char PRINT_GAME_AT_POSITION = 'u';
        char MOVE = 'm';
        char RIGHT = 'r';
        char LEFT = 'l';

        char * input = read_line();
        char first_command = input[0];
        char second_command = input[1];
        is_there_input = strlen(input);

        if (!is_there_input) {
            return 0;
        }
        else if (first_command == PRINT_CATALOG) {
            print_Catalog(catalog);
        }
        else if (first_command == PRINT_CATALOG_BY_COMPANY) {
            char* company = (char*) malloc(sizeof(char) * strlen(input));
            strcpy(PARSE_MASK, "p %[^\r\n]");
            sscanf(input, PARSE_MASK, company);
            print_Catalog_by_company(catalog, company);
        }
        else if (first_command == REMOVE_DUPLICATED_GAMES) {
            remove_duplicated_games_from_Catalog(catalog);
        }
        else if (first_command == PRINT_CATALOG_BY_YEAR) {
            char* year = (char*) malloc(sizeof(char) * strlen(input));
            strcpy(PARSE_MASK,"a %[^\r\n]");
            sscanf(input,PARSE_MASK, year);
            print_Catalog_by_year(catalog, year);
        }
        else if (first_command == FREE) {
            fclose(csv);
            return 0;
        }
        else if (first_command == PRINT_GAME_AT_POSITION) {
            int position;
            strcpy(PARSE_MASK,"u %d");
            sscanf(input, PARSE_MASK, &position);
            print_game_at_Catalog_position(catalog, position);
        }
        else if (first_command == MOVE && second_command == RIGHT) {
            int position;
            int quantity;
            strcpy(PARSE_MASK,"mr %d %d");
            move_Catalogue_game_at_position_quantity_times_right(catalog, position, quantity);
        }
        else if (first_command == MOVE && second_command == LEFT) {
            int position;
            int quantity;
            strcpy(PARSE_MASK, "ml %d %d");
            sscanf(input, PARSE_MASK, &position, &quantity);
            move_Catalogue_game_at_position_quantity_times_left(catalog, position, quantity);
        }
    }

}

