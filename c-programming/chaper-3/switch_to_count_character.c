#include<stdio.h>

int main(){
    char *inputString = NULL;
    int digit_count[10] = {0};
    int len = 0;
    int i = 0;
    int others = 0;
    printf("Enter input string to count the character: \n");
    getline(&inputString, &len, stdin);


    while(inputString[i] != '\0'){
        
        switch (inputString[i])
        {
            case '0': case '1': case '2': case '3': case '4' : case '5': case '6': case '7': case '8': case '9':
                digit_count[inputString[i]-'0']++;
                break;
            
            default:
                others++;
                break;
        }
        i++;
    }

    for(i = 0; i < 10; i++){
        printf("%d is %d times\n", i, digit_count[i]);
    }
    printf("%d other characters present into string \n", others);
    return 0;

}