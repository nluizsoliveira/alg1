#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline.h>
#include<memory.h>
#include<tree.h>
#include<game.h>

void handle_print_order_switch(Tree* tree, int mode){
    if (mode == 1){
        pre_order_transverse(tree);
    } else if (mode == 2) {
        in_order_transverse(tree);
    } else if (mode == 3){
        post_order_transverse(tree);
    }
}

void remove_ghost_headers(FILE* file){
    char byte;
    fscanf(file,"%c", &byte);
    fscanf(file,"%c", &byte);
    fscanf(file,"%c", &byte);
}

int main() {
    Tree* tree = new_tree();
    char filepath[10]= "CSV.csv";
    char mode[1] = "r";

    FILE* file = fopen(filepath, mode);
    remove_ghost_headers(file);
    
    int print_mode;
    int is_line_valid = true;
    int is_input_valid = true;
    char PARSE_MASK[18] = "%[^;];%[^;];%[^;]";
    char* line;
    char* input;
    char* name;
    char* year;
    char* company;
    
    
    while(is_line_valid){
        line = read_line(file);
        is_line_valid = strlen(line);

        if(is_line_valid){
            name = (char*) malloc(sizeof(char) * strlen(line));
            year = (char*) malloc(sizeof(char) *strlen(line));
            company = (char*) malloc(sizeof(char) *strlen(line));

            check_pointer(name);
            check_pointer(year);
            check_pointer(company);

            sscanf(line, PARSE_MASK, name, year, company);
            Game* game = new_Game(name, year, company);

            insert(tree, game);
        }
    }


    print_mode = (int) read_line(stdin)[0] - '0';
    
    while(is_input_valid){
        input = read_line(stdin);
        if(strcmp(input, "F") != 0){
            // remove input
        } else {
            is_input_valid = false;
        }
    }

    handle_print_order_switch(tree, print_mode);
    free_tree(tree);
}