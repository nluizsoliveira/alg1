#include<card.h>
#include<stdlib.h>
#include<string.h>

Card* create_Card_from_suit_and_rank(char*suit, char*rank){
    Card* card = malloc(sizeof(card));
    card ->suit = malloc(sizeof(strlen(suit)));
    card ->rank = malloc(sizeof(strlen(rank)));
    strcpy(card->suit, suit);
    strcpy(card->rank, rank);
    card->value = get_Card_value_from_rank(card->rank);

    return card;
}

int get_Card_value_from_rank(char*rank){
    int is_special_card = get_is_special_card_from_rank(rank);
    if(is_special_card){
        return 10;
    }
    return atoi(rank);
}

int get_is_special_card_from_rank (char*rank){
    const char *JACK = "V";
    const char *QUEEN = "D";
    const char *KING = "R";

    int is_special_card;
    int cumulative_rank_comparison = -1;

    /* 
        Strcmp returns 0 when compared Strings have the same content. (unintuitive, it's not 1)
        Using multiplications, after all comparisons, cumulative_rank_comparison 
        will store 0 if the card rank matches with the special ones. 
    */
    cumulative_rank_comparison *= strcmp(rank, JACK);
    cumulative_rank_comparison *= strcmp(rank, QUEEN);
    cumulative_rank_comparison *= strcmp(rank, KING);

    //  Due to strcmp return, it's needed to compare with 0. (I'm probably wrong though)
    is_special_card = cumulative_rank_comparison == 0;

    return is_special_card;
}


void delete_Card(Card* card){
    free(card->suit);
    card->suit = NULL;

    free(card->rank);
    card->rank = NULL;

    free(card);
    card = NULL;
}