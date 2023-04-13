#include<stdlib.h>
#include<memory.h>
#include<person.h>
#include<node.h>
#include<stdio.h>
#include<cpf.h>

Node* new_node(Person* person){
    Node* node = (Node*) malloc(sizeof(Node));
    check_pointer(node);

    node-> person = person;
    node->left = NULL;
    node->right = NULL;

    return node;

}

Node* insert_node(Node* node, Person* person){
    // Left insertion: persons CPF's smaller than nodes cpf.
    if(person->cpf < node->person->cpf){
        // Destiny node's empty: It's possible to insert directly.
        if(node->left == NULL){
            node->left = new_node(person);
        }
        // Destiny node's occupied. It's necessary to call method again.
        else{
            insert_node(node->left, person);
        }
    }

    // Right insertion. Same logic from above; persons CPF's bigger than nodes CPF.
    else{
        if(node->right == NULL){
            node->right = new_node(person);
        }
        else{
            insert_node(node->right, person);
        }
    }

}

void pre_order_transverse_node(Node* node){
    if(node!= NULL){
        print_cpf(node->person->cpf);
        pre_order_transverse_node(node->left);
        pre_order_transverse_node(node->right);
    }
}

void in_order_transverse_node(Node* node){
    if(node!= NULL){
        in_order_transverse_node(node->left);
        print_cpf(node->person->cpf);
        in_order_transverse_node(node->right);
    }
}

void post_order_transverse_node(Node* node){
    if(node!= NULL){
        post_order_transverse_node(node->left);
        post_order_transverse_node(node->right);
        print_cpf(node->person->cpf);
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