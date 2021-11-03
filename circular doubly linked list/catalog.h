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
#endif