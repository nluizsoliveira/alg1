#ifndef _node_
#define _node_	

#include<game.h>
typedef struct node{
    struct node* left;
    struct node* right;
    Game* game;
} Node;

Node* new_node(Game* game);
Node* insert_node(Node* node, Game* game);
int get_comparison(Game* game, Node* node);
int get_balance_factor(Node* node);
int get_height(Node* node);
Node* right_rotation(Node* node);
Node* left_rotation(Node* node);
Node* double_right_rotation(Node* node);
Node* double_left_rotation(Node* node);
void pre_order_transverse_node(Node* node);
void in_order_transverse_node(Node* node);
void post_order_transverse_node(Node* node);
void free_node(Node* node);

#endif
