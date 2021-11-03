#include<catalog.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

Catalog* new_Catalog(){
    Catalog* catalog = (Catalog*) malloc(sizeof(Catalog));
    catalog->size = 0;
    catalog->first = NULL;

    return catalog;
};

void add_Game_to_Catalog(Game* game, Catalog* catalog){
    if(catalog->size == 0) {
        catalog->first = game;
    }

    else if(catalog->size == 1) {
        catalog->first->next = game;
        catalog->first->before = game;
        game->next = catalog->first;
        game->before = catalog->first;
    }

    else {
        catalog->first->before->next = game;
        catalog->first->before= game;
        game->before = catalog->first->before;
        game->next = catalog->first;
    }

    catalog->size++;
}

void print_Catalog(Catalog* catalog){
    Game* game = catalog->first;
    for(int counter = 0; counter < catalog->size; counter++) {
        printf("%s\n", game->name);
        game = game->next;
    }
}

void print_Catalog_by_company(Catalog* catalog, char* company){
    Game* game = catalog->first;
    for(int counter = 0; counter < catalog->size; counter++) {
        if(strcmp(company, game->company) == 0){
            printf("%s\n", game->name);
        }
        game = game->next;
    }
}

void print_Catalog_by_year(Catalog* catalog, char* year){
    Game* game = catalog->first;
    for(int counter = 0; counter < catalog->size; counter++) {
        if(strcmp(year, game->year) == 0){
            printf("%s\n", game->name);
        }
        game = game->next;
    }
}