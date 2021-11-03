#include<game.h>
#include<stdlib.h>
#include<string.h>

Game* new_Game(char*name, char*year, char*company){
    Game* game = (Game*) malloc (sizeof(Game));

    game->name = (char*) malloc(sizeof(char) * strlen(name));
    game->year = (char*) malloc(sizeof(char) * strlen(year));
    game->company = (char*) malloc(sizeof(char) * strlen(company));
    
    strcpy(game->name, name);
    strcpy(game->year, year);
    strcpy(game->company, company);

    game-> next = NULL;
    game-> before = NULL;

    return game;
}

void* swap_games(Game* game1, Game*game2){
    char* tmp_name = game1->name;
    char* tmp_year = game1->year;
    char* tmp_company = game1->company;

    game1->name = game2->name;
    game1->year = game2->year;
    game1->company = game2->company;

    game2->name = tmp_name;
    game2->year = tmp_year;
    game2->company = tmp_company;
}

