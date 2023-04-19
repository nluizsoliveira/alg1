#ifndef _bookrecord_
#define _bookrecord_

#include<book.h>

typedef struct book_record{
    Book* book;
    char first_separator;
    char second_separator;
    int len_author; 
    int size;
    int byte_offset; 
} Book_Record;

Book_Record* new_book_record(Book* book, int last_byteoffset, int last_size);
int get_byteoffset(int last_byteoffset, int last_size);
int get_size(Book_Record* book_record); 
void print_book_record(Book_Record* book_record);
void write_book_record(FILE* file, Book_Record* book_record);
Book_Record* read_book_record(FILE* file);

#endif

