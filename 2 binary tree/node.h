#ifndef _node_
#define _node_	

#include<person.h>

typedef struct node{
    struct node* left;
    struct node* right;
    Person* person;
} Node;

Node* new_node(Person* person);
Node* insert_node(Node* node, Person* person);
void pre_order_transverse_node(Node* node);
void in_order_transverse_node(Node* node);
void post_order_transverse_node(Node* node);
void free_node(Node* node);

#endif
