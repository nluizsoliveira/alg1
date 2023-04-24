#ifndef _bookrecord_
#define _bookrecord_

#include<book.h>

typedef struct book_record{
    Book* book;
    char separator1;
    char separator2;
    int len_author; 
    int size;
    int byte_offset; 
} Book_Record;

Book_Record* new_book_record(Book* book, int last_byteoffset, int last_size);
int get_byteoffset(int last_byteoffset, int last_size);
int get_size(Book_Record* book_record); 
void print_book_record(Book_Record* book_record);
void write_book_record(FILE* file, Book_Record* book_record);
void* read_book_record(FILE* file);
char* read_field_until_separator(FILE* file, char separator);
char* increase_string(char* string, char char_, int length);


#endif

