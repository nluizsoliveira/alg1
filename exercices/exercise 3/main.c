#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<readline.h>
#include<card.h>
#include<deck.h>

int main () {
    char suit[7];
    char rank[3];


    Deck* deck = create_Deck();

    for(int i = 0; i < 52; i ++) {
        char* raw_line = read_line();
        sscanf(raw_line, "%s %s", suit, rank);
        push_to_Deck_from_suit_and_rank(suit, rank, deck);
    }

    int points = 0;
    bool game = true;
    
    while(game){
        points = points + pop_from_Deck(deck);

        if(points == 21){
            printf("Ganhou ;)");
            return 0;
        }

        if(points > 21){
            printf("Perdeu :(\nSoma :: %d", points);
            return 0;
        }
    }


    return 0;
}

