#include<stdlib.h>
#include<memory.h>
#include<tree.h>
#include<stdio.h>

void insert(Tree* tree, Person* person){
    if(tree->root == NULL){
        tree->root = new_node(person);
    }
    else{
        insert_node(tree->root, person);
    }
}

Tree* new_tree(){
    Tree* tree = (Tree*) malloc(sizeof(tree));
    check_pointer(tree);
    tree->root = NULL;
    return tree;
}

void pre_order_transverse(Tree* tree){
    printf("Preorder\n");
    pre_order_transverse_node(tree->root);
    printf("\n");

}

void in_order_transverse(Tree* tree){
    printf("Inorder\n");
    in_order_transverse_node(tree->root);
    printf("\n");

}

void post_order_transverse(Tree* tree){
    printf("Postorder\n");
    post_order_transverse_node(tree->root);
    printf("\n");
}

void free_tree(Tree* tree){
    free_node(tree->root);
}