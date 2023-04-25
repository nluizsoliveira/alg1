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
void* write_index(FILE* file, Index* index);
Book Record** read_last_N_index_lines(Index* index, int N);


#endif
