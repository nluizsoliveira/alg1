#include<deck.h>
#include<card.h>
#include<stdlib.h>
#include<stdio.h>

Node* create_Node_from_suit_and_rank(char* suit, char*rank){
    Node* node = malloc(sizeof(node));
    node->card = create_Card_from_suit_and_rank(suit, rank);
    node->next = NULL;

    return node;
}

Deck* create_Deck (){
    Deck* deck = malloc(sizeof(Deck));
    deck->top = NULL;
    deck->size = 0;

    return deck;
}

struct node* get_Deck_penultimate_node(Deck* deck) {
    struct node* penultimate_node = malloc(sizeof(struct node));
    penultimate_node = deck->top;

    while((penultimate_node -> next )-> next != NULL) {
        penultimate_node = penultimate_node->next;
    }

    return penultimate_node;
}

void push_to_Deck_from_suit_and_rank(char* suit, char* rank, Deck* deck){
    Node* node = create_Node_from_suit_and_rank(suit, rank);    
    deck->size++;
    node->next = deck->top; 
    deck->top = node;
    printf("Size: %d. top: suit[%s]rank[%s]value[%d]\n", deck->size, deck->top->card->suit, deck->top->card->rank, deck->top->card->value);
    }

int pop_from_Deck(Deck* deck){
    int popped_value  = deck->top->card->value; 

    deck->top = deck->top->next;
    deck->size--;
    
    return popped_value;
    
}