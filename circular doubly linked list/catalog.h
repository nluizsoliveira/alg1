#ifndef _catalog_
#define _catalog_	

#include<game.h>

typedef struct catalog{
    int size;
    Game* first;
} Catalog;

Catalog* new_Catalog();
void add_Game_to_Catalog(Game* game, Catalog* catalog);
void print_Catalog(Catalog* catalog);
void print_Catalog_by_company(Catalog* catalog, char* company);
void print_Catalog_by_year(Catalog* catalog, char* company);
void remove_duplicated_games_from_Catalog(Catalog* catalog);
void print_game_at_Catalog_position(Catalog* catalog, int position);
void move_Catalogue_game_at_position_quantity_times_right(Catalog* catalog, int position, int quantity);
void move_Catalogue_game_at_position_quantity_times_left(Catalog* catalog, int position, int quantity);
#endif