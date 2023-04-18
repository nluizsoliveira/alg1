#include<stdio.h>
#include<book.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

Book* new_book(int id, char* title, char* author){
    Book * book = (Book*) malloc(sizeof(Book));
    check_pointer(book);

    book->title = (char*) malloc(sizeof(char) * strlen(title));
    book->author = (char*) malloc(sizeof(char) * strlen(author));

    check_pointer(book->title);
    check_pointer(book->author);

    book->id = id; 
    strcpy(book->title, title); 
    strcpy(book->author, author);

    return book;
}

void print_book(Book* book){
    printf("\nid: %d | title: %s | author: %s\n", book->id, book->title, book->author);
}