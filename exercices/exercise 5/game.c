#include<game.h>
#include<stdlib.h>
#include<string.h>

Game* new_Game(char*name, char*year, char*company){
    Game* game = (Game*) malloc (sizeof(Game*));
    game->name = (char*) malloc(sizeof(char) * strlen(name));
    game->year = (char*) malloc(sizeof(char) * strlen(year));
    game->company = (char*) malloc(sizeof(char) * strlen(company));
    strcpy(game->name, name);
    strcpy(game->year, year);
    strcpy(game->company, company);
    return game;
}