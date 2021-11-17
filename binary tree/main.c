#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cpf.h>
#include<readline.h>

int main(){
    int clients_quantity;
    scanf("%d ", &clients_quantity);

    for(int counter = 0; counter < clients_quantity; counter++){
        char* client_info_string = read_line();
        char* cpf_with_special_characters = (char*) malloc(strlen(client_info_string) * sizeof(char));
        unsigned long long int cpf;
        char* name = (char*) malloc(strlen(client_info_string) * sizeof(char));
        int age;
        double balance;

        sscanf(client_info_string, "%[^;];%[^;];%d;%lf", cpf_with_special_characters, name, &age, &balance);
        cpf = parse_cpf(cpf_with_special_characters);
        printf("---%llu %s %d %lf ---\n", cpf, name, age, balance);

    }

    return 0;
}