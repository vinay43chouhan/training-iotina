#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int input = -1;
    int exit = -1;
    printf("Enter the size of the stack: \n");
    scanf("%d", &capacity);

    stack = (int*)calloc(capacity, sizeof(int));
    if(!stack){
        // TODO print
        return -1;
    }

    while(input != 5){
        printf("Please enter 0: push, 1: pop, 2: top, 3: isEmpty, 4: size, 5: exit");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("Please enter a number you want to push: ");
            int number = 0;
            scanf("%d", &number);
            push(number);
            break;

        case 1:
            int popped_number = pop();
            printf("%d is popped from the stack.\n", popped_number);
            break;
        
        case 2:
            int top_element = top();
            printf("%d is the top element on the stack.\n", top_element);
            break;
        
        case 3:
            ( isEmpty() == true ) ? printf("Stack is empty.\n") : printf("Stack is not empty.\n");
            break;
        
        case 4:
            printf("Size of the stack is %d.\n", size());
            break;

        case 5:
            exit = 5;
            break;
        default:
            printStack();
            break;
        }

        if(exit == 5){
            break;
        }

    }
    return 0;

}