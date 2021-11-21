#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cpf.h>
#include<readline.h>
#include<memory.h>
#include<person.h>
#include<tree.h>

int main(){
    int clients_quantity;
    scanf("%d ", &clients_quantity);

    Tree* tree = new_tree();
    for(int counter = 0; counter < clients_quantity; counter++){
        const char PARSE_CSV_MASK[20] = "%[^;];%[^;];%d;%lf";
        int age;
        double balance;
        unsigned long long int cpf;

        char* client_info_string = read_line();
        check_pointer(client_info_string);

        char* cpf_with_special_characters = (char*) malloc(strlen(client_info_string) * sizeof(char));
        check_pointer(cpf_with_special_characters);

        char* name = (char*) malloc(strlen(client_info_string) * sizeof(char));
        check_pointer(name);
        
        sscanf(client_info_string, PARSE_CSV_MASK, cpf_with_special_characters, name, &age, &balance);
        cpf = parse_cpf(cpf_with_special_characters);

        Person* person = new_person(cpf,name,age,balance);
        insert(tree, person);
    }

    in_order_transverse(tree);
    pre_order_transverse(tree);
    post_order_transverse(tree);

    free_tree(tree);

    return 0;
}