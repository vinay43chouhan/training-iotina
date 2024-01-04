#include<stdio.h>

int main(){
    char name[] = "iotina technology";
    char removing_char[] = "otp";
    int i =0;
    
    while(removing_char[i]!='\0'){
        char ch = removing_char[i++];
        int j = 0;
        int k = 0;
        int y =0;
        while(name[y]!='\0'){
            y++;
        }
        int size = y+1;
        printf("size = %d\n",size);
        char new_memory[size];
        while(name[j]!='\0'){
            if(ch == name[j]){
                j++;
                continue;
            }
            new_memory[k] = name[j];
            j++;
            k++;
        }
        new_memory[k] = '\0';

        int x =0;
        while(new_memory[x] != '\0'){
            name[x] = new_memory[x];
            x++;
        }
        name[x] = '\0';
    }
    i=0;
    while(name[i]!='\0'){
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
    return 0;
}