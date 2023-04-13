#ifndef _tree_
#define _tree_

#include<node.h>

typedef struct tree{
    Node* root;
} Tree;

void insert(Tree* tree, Game* game);
Tree* new_tree();
void pre_order_transverse(Tree* tree);
void in_order_transverse(Tree* tree);
void post_order_transverse(Tree* tree);
void free_tree(Tree* tree);

#endif