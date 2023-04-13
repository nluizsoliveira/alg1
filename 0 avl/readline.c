#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<readline.h>
#include<memory.h>

char* read_line(FILE* file){
    const char C_STRING_TERMINATOR = '\0';
    char* line = NULL;
    int length = 0;
    bool is_char_nonterminal = true;
    bool is_line_empty = true;
    char char_;
    
    while(is_char_nonterminal){
        char_ = read_char(file);
        is_char_nonterminal *= !is_end_of_line(char_);
        is_char_nonterminal *= !is_unix_linebreak(char_);
        is_char_nonterminal *= !is_windows_linebreak(char_, file);
        

        if(is_char_nonterminal){
            line = append_char(line, char_, length);
            length ++;
            is_line_empty = false;
        }
        
    }

    if(is_line_empty) return "";
    
    line = append_char(line, C_STRING_TERMINATOR, length);
    return line; 
}

char read_char(FILE* file){
    return (char) fgetc(file);
}

bool is_end_of_line(char char_){
    return char_ == EOF;
}

bool is_unix_linebreak(char char_){
    const char UNIX_LINEBREAK = '\n';
    return char_ == UNIX_LINEBREAK;
}

bool is_windows_linebreak(char char_, FILE* file) {
    const char WINDOWS_LINEBREAK = '\r';
    bool is_windows_linebreak = char_ == WINDOWS_LINEBREAK;
    handle_windows_linebreak(is_windows_linebreak, file);
    return is_windows_linebreak;
}

void handle_windows_linebreak(bool is_windows_linebreak, FILE* file){
    char extra_linebreak;
    if(is_windows_linebreak){
        extra_linebreak = read_char(file);
    }
}

char* append_char(char* line, char char_, int length){
    line = (char*) realloc(line, sizeof(char) * (length +  1));
    check_pointer(line);
    line[length] = char_;
    return line;
}