#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){
    char ch;
    char *line = NULL;
    size_t size = 0;
    int line_no = 0;
    int except = 0, found = -1, number = 0;

    while( --argc > 0 && (*++argv)[0] == '-'){
        while((ch = *++argv[0])){ // *(++(*(argv + 0)))
            switch (ch)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                found = 0;
                printf("Not found\n");
                break;
            }
        }
    }

    if(argc != 1){
        printf("Usage: find -x -n pattern\n");
    }else{
        while( printf("Enter a line: ") && getline(&line, &size, stdin) > 1){
            line_no++;
            if( (strstr(line, *argv) != NULL ) != except){
                if(number){
                    printf("%d: %s", line_no, line);
                }else{
                    printf("%s", line);
                }
                
                found++;
            }
            printf("Hit enter to exit.\n");
        }
    }
    printf("pattern is present %d times.\n", found+1);
    return 0;
}
