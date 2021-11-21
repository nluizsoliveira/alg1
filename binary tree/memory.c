#include<stdio.h>
int check_pointer(void* pointer){
    if(pointer == NULL){
        printf("Malloc failed. You may have tried to allocate more memory than available. Your memory may be defragmented\n");
        printf("There may be other reasons. Malloc may have just failed.\n");
        return 0;
    }
}
