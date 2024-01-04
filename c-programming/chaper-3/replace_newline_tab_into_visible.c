/**
 * @file replace_newline_tab_into_visible.c
 * @author Vinay Chouhan
 * @brief we are replace newline, tab with visible escape squence like /n and /t 
 * @date 2023-12-27
 * 
 */

#include <stdio.h>

int main(){
    char paragraph[] = "Hi, My name is vinay    \n"
                        "You can call me by any name.\n\t        ";
    int paragraph_index = 0;
    
    char buffer[1000];
    int buffer_index = 0;

    while (paragraph[paragraph_index] != '\0'){
        if (paragraph[paragraph_index] == '\n'){
            buffer[buffer_index++] = '\\';
            buffer[buffer_index++] = 'n';
        }else if (paragraph[paragraph_index] == '\t'){
            buffer[buffer_index++] = '\\';
            buffer[buffer_index++] = 't';
        }else{
            buffer[buffer_index++] = paragraph[paragraph_index];
        }
        paragraph_index++;
    }
    /*
    while (paragraph[paragraph_index] != '\0'){
        switch (paragraph[paragraph_index])
        {
        case '\n':
            buffer[buffer_index++] = '\\';
            buffer[buffer_index++] = 'n';
            paragraph_index++;
            break;
        
        case '\t':
            buffer[buffer_index++] = '\\';
            buffer[buffer_index++] = 't';
            paragraph_index++;
            break;
        default:
            buffer[buffer_index++] = paragraph[paragraph_index];
            paragraph_index++;
            break;
        }
    }
    */
    buffer[buffer_index] = '\0';
    printf("%s", buffer);
    return 0;
}
