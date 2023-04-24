#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<bookrecord.h>

Book_Record* new_book_record(Book* book, int last_byteoffset, int last_size){
    Book_Record* book_record = (Book_Record*) malloc(sizeof(Book_Record));
    check_pointer(book_record);

    book_record-> book = book; 
    book_record-> separator1 = '|';
    book_record-> separator2 = '\n';
    book_record-> len_author = strlen(book->author);
    book_record-> size = get_size(book_record);
    book_record-> byte_offset = get_byteoffset(last_byteoffset, last_size);

    return book_record;
}

int get_size(Book_Record* book_record){
    // [id][title][separator1][authorLen][author][separator2]
    // ex: 10The Hunger Games|15Suzanne Collins-1

    Book* book = book_record-> book; 

    int sizeId = sizeof(book->id);
    int lenTitle= strlen(book->title);
    int sizeSeparator1 = sizeof(book_record->separator1);
    int sizeAuthorLen = sizeof(book_record->len_author);
    int lenAuthor = strlen(book->author);
    int sizeSeparator2 = sizeof(book_record->separator2);
 

    return sizeId + lenTitle + sizeSeparator1 + 
            sizeAuthorLen + lenAuthor + sizeSeparator2; 
    
}

int get_byteoffset(int last_byteoffset, int last_size){
    return last_byteoffset + last_size;
}

void write_book_record(FILE* file, Book_Record* book_record){
    Book* book = book_record-> book; 
    printf("ID: Valor escrito: [%d], de tamanho %ld\n", book->id, sizeof(book->id));
    fwrite(&(book->id), sizeof(book->id), 1, file);
    fwrite(book->title, strlen(book->title), 1, file);
    printf("Titulo: Valor escrito: [%s], de tamanho %ld\n", book->title, strlen(book->title));

    fwrite(&(book_record->separator1), sizeof(book_record->separator1), 1, file);
    printf("Separador: Valor escrito: [%c], de tamanho %ld\n", book_record->separator1, sizeof(book_record->separator1));

}

void* read_book_record(FILE* file){
    int id;
    char* title; 

    fread(&id, sizeof(int), 1, file);
    title = read_field_until_separator(file, '|');
    
    printf("ID -> %d\n", id);
    printf("title -> %s\n", title);
}

char* read_field_until_separator(FILE* file, char separator){
    const char C_STRING_TERMINATOR = '\0';
    char* field= NULL; 
    char cursor = ' ';
    int length = 0; 

    printf("Entrou!!!\n");
    
    while(cursor != separator){
        printf("-> %c\n", cursor);
        fread(&cursor, sizeof(char), 1, file);
        if(cursor != separator){
            field = increase_string(field, cursor, length);
        }
        length++; 
    }
    field = increase_string(field, C_STRING_TERMINATOR, length);
    return field; 
}

char* increase_string(char* string, char char_, int length){
    string = (char*) realloc(string, sizeof(char) * (length +  1));
    check_pointer(string);
    string[length] = char_;
    return string;
}

void print_book_record(Book_Record* book_record){
    Book* book = book_record-> book; 
    printf("%d%s%c%d%s%c", 
            book->id, 
            book->title,
            book_record->separator1,
            book_record->len_author,
            book->author,
            book_record->separator2
        );
}