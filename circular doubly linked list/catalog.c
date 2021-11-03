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

// to be refactored
void add_Game_to_Catalog(Game* game, Catalog* catalog){
    if(catalog->size == 0) {
        catalog->first = game;
    }

    else if(catalog->size == 1) {
        game->next = catalog->first;
        game->before = catalog->first;

        catalog->first->next = game;
        catalog->first->before = game;
        
    }

    else if (catalog->size == 2) {
        game->next = catalog->first;
        game->before = catalog->first->next;
        

        catalog->first->before->next = game;
        catalog->first->before= game;
    }

    else {
        game->next = catalog->first;
        game->before = catalog->first->before;

        catalog->first->before->next = game;
        catalog->first->before= game;
    }

    catalog->size++;
}

void print_Catalog(Catalog* catalog){
    Game* game = catalog->first;
    for(int counter = 0; counter < catalog->size; counter++) {
        printf("%s\n",game->name);
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


void remove_duplicated_games_from_Catalog(Catalog* catalog) {
    
}

void print_game_at_Catalog_position(Catalog* catalog, int position){
    Game* game = catalog->first;
    for(int counter = 0; counter < position; counter++) {
        game = game->next;
    }
    printf("%s\n", game->name);
}

// Funções abaixo estão bugadas para caso de teste 4. (mr 19 1). Modificar para mover lista inteira caso
// estoure a borda
void move_Catalogue_game_at_position_quantity_times_right(Catalog* catalog, int position, int quantity) {
    Game* game = catalog->first;
    for(int counter = 0; counter < position; counter++) {
        game = game->next;
    }
    while(quantity > 0) {
        swap_games(game, game->next);
        quantity--;
        game = game->next;
    }
}

void move_Catalogue_game_at_position_quantity_times_left(Catalog* catalog, int position, int quantity) {
    Game* game = catalog->first;

    for(int counter = 0; counter < position; counter++) {
        game = game->next;
    }

    while(quantity > 0) {
        swap_games(game, game->before);
        quantity--;
        game = game->before;
    }
}