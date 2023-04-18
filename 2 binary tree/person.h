#ifndef _person_
#define _person_

typedef struct person {
    long long int cpf;
    char* name;
    int age;
    double balance;
} Person;

Person* new_person(long long int cpf, char* name, int age, double balance);
void print_person(Person* person);

#endif