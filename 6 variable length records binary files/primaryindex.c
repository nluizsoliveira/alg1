#include<primaryindex.h>
#include<memory.h>

Index_Line* new_index_line(int id, int byte_offset){
    Index_Line* index_line = (Index_Line*) malloc(sizeof(Index_Line));
    check_pointer(index_line);
    index_line->id = id; 
    index_line->byte_offset = byte_offset;

    return index_line; 
}

void* write_index(FILE* file, Index* index){
    fwrite(index->index_lines, )
}

