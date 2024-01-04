#include<stdio.h>

// teminate at newline
void using_fgets(){
    char name_of_company[100];
    fgets(name_of_company,sizeof(name_of_company), stdin);

    int i =0;
    while(name_of_company[i]!='\0'){
        printf("%c", name_of_company[i]);
        i++;
    }
    printf("\n");

}

// It will terminate by space, newline and tab
void using_scanf(){
    char name_of_company[100];
    scanf("%99s", name_of_company);
    printf("%s", name_of_company);
    printf("\n");

}

int main(){
    using_fgets();
    using_scanf();
    return 0;
}