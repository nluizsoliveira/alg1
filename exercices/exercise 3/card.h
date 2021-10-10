#ifndef _card_
#define _card_	

typedef struct card {
    char* suit;
    char* rank;
    int value;
} Card;

Card* create_Card_from_suit_and_rank(char*suit, char*rank);
int get_Card_value_from_rank(char*rank);
int get_is_special_card_from_rank (char*rank);
void delete_Card(Card* card);

#endif