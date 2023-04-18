#ifndef _book_
#define _book_

typedef struct book{
    int id; 
    char* title; 
    char* author;
} Book;


Book* new_book(int cpf, char* title, char* author);
void print_book(Book* book);

#endif