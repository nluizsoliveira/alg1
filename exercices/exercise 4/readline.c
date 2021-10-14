#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<readline.h>

char* read_line(){
    const char UNIX_LINEBREAK = '\n';
    const char WINDOWS_LINEBREAK = '\r';
    const char C_STRING_TERMINATOR = '\0';
    
    char extra_linebreak;
    char current_letter;

    char* line = NULL;
    int position = 0;
    bool reading_line = true;
    

    while(reading_line){
        scanf("%c", &current_letter);
        if(current_letter == UNIX_LINEBREAK){
            reading_line = false;
        }
        else if(current_letter == WINDOWS_LINEBREAK) {
            reading_line = false;
            extra_linebreak = (char)getchar();
        }
        else {
            line = (char*) realloc(line, sizeof(char) * (position +  1));
            line[position] = current_letter;
            position ++;
        }
    }

    line = (char*) realloc(line, sizeof(char) * (position +  1));
    line[position] = C_STRING_TERMINATOR;

    return line; 
}

