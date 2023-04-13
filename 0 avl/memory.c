#include<stdio.h>
#include<stdlib.h>
void check_pointer(void* pointer){
    if(pointer == NULL){
        perror("malloc failed!");
        exit(EXIT_FAILURE);
    }
}
