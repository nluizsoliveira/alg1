#ifndef _readline_
#define _readline_	
#include<stdbool.h>

char* append_char(char* line, char char_, int length);
void handle_windows_linebreak(bool is_windows_linebreak, FILE* file);
bool is_end_of_line(char char_);
bool is_unix_linebreak(char char_);
bool is_windows_linebreak(char char_, FILE* file);
char* read_line(FILE* file);
char read_char(FILE* file);

#endif