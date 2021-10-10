#ifndef _deck_
#define _deck_	

#include<card.h>

typedef struct node {
    Card* card;
    struct node * next;
} Node;

typedef struct deck {
    Node* top;
    int size; 
} Deck;

Node* create_Node_from_suit_and_rank(char* suit, char*rank);
Deck* create_Deck ();
struct node* get_Deck_penultimate_node(Deck* deck);
void push_to_Deck_from_suit_and_rank(char* suit, char* rank, Deck* deck);
int pop_from_Deck(Deck* deck);

#endif