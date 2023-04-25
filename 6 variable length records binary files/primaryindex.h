#ifndef _primaryindex_
#define _primaryindex_

typedef struct index_line{
    int id;
    int byte_offset; 
} Index_Line;

typedef struct index{
    int size;
    Index_Line** index_lines;
} Index; 

Index_Line* new_index_line(int id; int byte_offset); 
void* write_index(FILE* file, Index_Line** index);
Book Record* read_book_record_from_index(FILE* file, int id);


#endif
