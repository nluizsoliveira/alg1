#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<bookrecord.h>

Book_Record* new_book_record(Book* book, int last_byteoffset, int last_size){
    Book_Record* book_record = (Book_Record*) malloc(sizeof(Book_Record));
    check_pointer(book_record);

    book_record-> book = book; 
    book_record-> first_separator = '|';
    book_record-> second_separator = '\n';
    book_record-> len_author = strlen(book->author);
    book_record-> size = get_size(book_record);
    book_record-> byte_offset = get_byte_offset(last_byteoffset, last_size);

    return book_record;
}


int get_size(Book_Record* book_record){
    // [id][title][separator1][authorLen][author][separator2]
    // ex: 10The Hunger Games|15Suzanne Collins-1

    Book* book = book_record-> book; 

    int sizeId = sizeof(book->id);
    int sizeTitle = sizeof(book->title);
    int separator1Size = sizeof(book_record->first_separator);
    int authorLenSize = sizeof(book_record->len_author);
    int authorLen = strlen(book->author);
    int separator2Size = sizeof(char);

    return sizeId + sizeTitle + separator1Size + 
            authorLenSize + authorLen + authorLenSize; 
}

int get_byteoffset(int last_byteoffset, int last_size){
    return last_byteoffset + last_size;
}
void print_book_record(Book_Record* book_record){
    Book* book = book_record-> book; 
    printf("%d%s%c%d%s%c", 
            book->id, 
            book->title,
            book_record->first_separator, 
            book_record->len_author, 
            book->author,
            book_record->second_separator
        );
}