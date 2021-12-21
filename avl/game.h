#ifndef _game_
#define _game_	

typedef struct game{
    char* name;
    char* year; 
    char* company;
} Game;

Game* new_Game(char*name, char*year, char*company);
void free_Game(Game* game);
#endif