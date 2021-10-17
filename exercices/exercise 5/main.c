#include<stdio.h>
#include<readline.h>
#include<stdbool.h>
#include<string.h>

typedef struct game{
    char* name;
    char* company;
    int year; 
} Game;

Game* new_Game(char*company, char*name, int year){
    Game* game = (Game*) malloc (sizeof(Game*));
    strcpy(game->name, name);
    strcpy(game->company, company);
    game->year = year;
    return game;
}

int main (){
    char csv_filepath[10]= "./CSV.csv";
    char mode[1] = "r";

    FILE* csv = fopen(csv_filepath, mode);

    char* line = read_line_from_file(csv);
    bool is_line_valid = strlen(line);

    while(is_line_valid){
        line = read_line_from_file(csv);
        is_line_valid = strlen(line);
    }
    fclose(csv);
    return 0;
}

