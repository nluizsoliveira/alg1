#include<game.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<memory.h>

Game* new_Game(char*name, char*year, char*company){
    Game* game = (Game*) malloc (sizeof(Game));
    check_pointer(game);

    game->name = (char*) malloc(sizeof(char) * strlen(name));
    game->year = (char*) malloc(sizeof(char) * strlen(year));
    game->company = (char*) malloc(sizeof(char) * strlen(company));

    check_pointer(game->name);
    check_pointer(game->year);
    check_pointer(game->company);
    
    strcpy(game->name, name);
    strcpy(game->year, year);
    strcpy(game->company, company);

    return game;
}

void free_Game(Game* game){
    free(game->name);
    free(game->year);
    free(game->company);
    game->name = NULL;
    game->year = NULL;
    game->company = NULL;

    free(game);
    game = NULL;
}