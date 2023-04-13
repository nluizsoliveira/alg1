#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<node.h>
#include<memory.h>
#include<game.h>


Node* new_node(Game* game){
    Node* node = (Node*) malloc(sizeof(Node));
    check_pointer(node);

    node-> game = game;
    node->left = NULL;
    node->right = NULL;

    return node;

}

Node* insert_node(Node* node, Game* game){
    if(node == NULL){
        return new_node(game);
    }

    int comparison = get_comparison(game, node);

    // As tree will balance itself, first glance insertion is more flexible.
    if(comparison < 0){
        node->left = insert_node(node->left,game);
    } else if (comparison > 0) {
        node->right = insert_node(node->right, game);
    } else {
        return node;
    }

    // balance nodes below if necessary
    int balance_factor = get_balance_factor(node);
    
    // if node's left unbalaced, it needs to be right rotated. 
    // if game's smaller than node, a single rotation is enough.
    // else, a double rotation is needed.  
    if(balance_factor == 2) {
        comparison = get_comparison(game, node->left);
        if(comparison < 0) {
            node = right_rotation(node);
        } else {
            node = double_right_rotation(node);
        }
    }

    // if node's right unbalaced, it needs to be left rotated.
    // Same logic from left balancing but side-reversed. 
    if(balance_factor == -2) {
        comparison = get_comparison(game, node->right);
        if(comparison > 0) {
            node = left_rotation(node);
        } else {
            node = double_left_rotation(node);
        }
    }

    return node;
}

int get_comparison(Game* game, Node* node){
    int comparison;
    int year_comparison = strcmp(game->year, node->game->year);
    int name_comparison = strcmp(game->name, node->game->name);

    comparison = year_comparison;
    if(year_comparison == 0){
        comparison = name_comparison;
    }

    return comparison;
}

// balance factor is the difference of height between left and right node. 
int get_balance_factor(Node* node){
    int left_heigth = get_height(node->left);
    int right_heigth = get_height(node->right);
    int balance_factor = left_heigth - right_heigth;

    return balance_factor;
}

// height is the maximum distance from a node to it's most distant leaf. 
int get_height(Node* node){
    if(node == NULL) {
        return -1;
    }
    int left_heigth = get_height(node->left);
    int right_heigth = get_height(node->right);
    if(left_heigth > right_heigth){
        return (left_heigth + 1);
    }
    return (right_heigth + 1);
}

Node* right_rotation(Node* node){
    Node* new_beginning = node->left;
    node->left = new_beginning->right;
    new_beginning->right = node;

    return new_beginning;
}

Node* left_rotation(Node* node){
    Node* new_beginning = node->right;
    node->right = new_beginning->left;
    new_beginning->left = node;
    return new_beginning;
}

Node* double_right_rotation(Node* node){
    node->left = left_rotation(node->left);
    Node* new_beginning = right_rotation(node);
    return new_beginning;
}

Node* double_left_rotation(Node* node){
    node->right = right_rotation(node->right);
    Node* new_beginning = left_rotation(node);
    return new_beginning;
}

void pre_order_transverse_node(Node* node){
    if(node!= NULL){
        printf("%s\n", node->game->name);
        pre_order_transverse_node(node->left);
        pre_order_transverse_node(node->right);
    }
}

void in_order_transverse_node(Node* node){
    if(node!= NULL){
        in_order_transverse_node(node->left);
        printf("%s\n", node->game->name);
        in_order_transverse_node(node->right);
    }
}

void post_order_transverse_node(Node* node){
    if(node!= NULL){
        post_order_transverse_node(node->left);
        post_order_transverse_node(node->right);
        printf("%s\n", node->game->name);
    }
}

void free_node(Node* node){
    if(node != NULL){
        Node* right_node = node->right;
        Node* left_node = node->left;

        free(node);
        node = NULL;
        free_node(right_node);
        free_node(left_node);
    }
}