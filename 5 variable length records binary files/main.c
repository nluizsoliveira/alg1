#include<stdio.h>
#include<readline.h>


int main(){
    int num_records; 
    scanf("%d ", &num_records);

    for(int record = 0; record < num_records; record++){
        int   id     ; scanf("%d ", &id);
        char* title  = read_line();
        char* author = read_line();

        printf("%d|%s|%s\n", id, title, author); 
    }
    return 0;
}