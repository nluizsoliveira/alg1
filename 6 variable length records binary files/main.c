#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline.h>
#include<book.h>


typedef struct book_record{
    Book* book;
    int len_author; 
    char first_separator; 
    char second_separator; 
    int byte_offset;
} Book_Record;

Book* new_book_from_stdin(){
    int   id     ; scanf("%d ", &id);
    char* title  = read_line(stdin);
    char* author = read_line(stdin);

    return new_book(id, title, author);
}

int main(){
    FILE *file;
    file = fopen("file","wb");
    if (file == NULL){
    	printf("error creating file\n");
    	exit;
	}

    int num_records; 
    scanf("%d ", &num_records);
    
    for(int record = 0; record < num_records; record++){
        Book* book = new_book_from_stdin();
        print_book(book);
        // char bin_record[100];
        // sprintf(bin_record, "%d%s|%d%s\n", id, title, len_author, author);


        // gerar linha unica com tudo junto, seguindo o seguinte formato: 
        // 10The Hunger Games|15Suzanne Collins-1
        // Criar arquivo com id e byte offset de cada um 
        // 

        // printf("%ld -> %s" , strlen(bin_record), bin_record); 

        // free(title);
        // free(author);
    }

    int num_restored_records; 
    scanf("%d", & num_restored_records);

    return 0;
}


// preciso saber o tamanho da linha lida
// para ? conseguir um babado fortissimo