#include<stdio.h>
#include<person.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

Person* new_person(long long int cpf, char* name, int age, double balance){
    Person* person = (Person*) malloc(sizeof(person));
    check_pointer(person);

    person->name = (char*) malloc(sizeof(char) * strlen(name));
    check_pointer(person->name);
    strcpy(person->name, name);
    
    person->cpf = cpf;
    person->age = age;
    person->balance = balance;
    
    return person;
}

void print_person(Person* person){
    printf("%llu %s %d %lf\n", person->cpf, person->name, person->age, person->balance);
}
