#include<stdlib.h>
#include<memory.h>
#include<tree.h>
#include<stdio.h>

void insert(Tree* tree, Game* game){
    tree->root = insert_node(tree->root, game);
}

Tree* new_tree(){
    Tree* tree = (Tree*) malloc(sizeof(tree));
    check_pointer(tree);
    tree->root = NULL;
    return tree;
}

void pre_order_transverse(Tree* tree){
    pre_order_transverse_node(tree->root);
}

void in_order_transverse(Tree* tree){
    in_order_transverse_node(tree->root);
}

void post_order_transverse(Tree* tree){
    post_order_transverse_node(tree->root);
}

void free_tree(Tree* tree){
    free_node(tree->root);
    free(tree);
    tree = NULL;
}