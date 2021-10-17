#ifndef _game_
#define _game_	

typedef struct game{
    char* name;
    char* year; 
    char* company;

    struct game* before;
    struct game* next;
} Game;

Game* new_Game(char*name, char*year, char*company);
#endif