#include<stdio.h>
#include<math.h>
#define MAXSIZE 1000

char *store_lines[MAXSIZE];

void copy(char input_line[], char longest_line[], size_t len);
void reversel(char* line, size_t size);
void printDB(char *storage[], int n);

int main(){
    char *input_line = NULL;
    char longest_line[MAXSIZE];
    size_t longest_line_size = 0;
    size_t len = 0;
    int current_position_to_store = 0;
    while((len = getline(&input_line, &len, stdin)) > 0){
        store_lines[current_position_to_store] = input_line;
        if(len > longest_line_size){
            longest_line_size = len;
            copy(input_line, longest_line, len);
        }
        printf("%u\n", len);
        printf("%u\n", longest_line_size);

        printf("Your longest line is: \n");
        int condition = (longest_line_size-1);
        for(int i=0;i<condition;i++){
            printf("%c", longest_line[i]);
        }
        
        
        if(len == 1){
            break;
        }
        reversel(input_line, len-1);
        printf("Your longest reversed line is: \n");
        for(size_t i=0;i<longest_line_size-1;i++){
            printf("%c", longest_line[i]);
        }

        printf("\n");
    }
    printDB(store_lines,current_position_to_store);

    return 0;
}

void copy(char input_line[], char longest_line[], size_t len){
    for(size_t i=0;i<len;i++){
        longest_line[i] = input_line[i];
    }
    
    return;
}

void reversel(char *line, size_t size){
    int i=0;
    int j = size-1;
    while(i<j){
        char temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        i++;
        j++;
    }
    return;
}

void printDB(char *storage[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;storage[i][j]!='\n';j++){
            printf("%c", storage[i][j]);
        }
        printf("\n");
    }
    return;
}
