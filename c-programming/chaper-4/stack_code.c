/* Stack is one of the data structure that follow fifo order*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define OUT_OF_MEM -1
#define POST 0
#define POP 1
#define TOP 2
#define IS_EMPTY 3
#define SIZE 4
#define EXIT 5

static int *stack = NULL;
static int next = -1;
static int capacity = 0;

void push(int number);
int pop();
int top();
bool isEmpty();
int size();
void printStack();

int main(){
    int input = -1;
    int exit = -1;
    printf("Enter the size of the stack: \n");
    scanf("%d", &capacity);

    stack = (int*)calloc(capacity, sizeof(int));
    if(!stack){
        printf("Memory is not allocate.\n");
        return OUT_OF_MEM;
    }

    while(input != 5){
        printf("Please enter your choice:\n 0: push\n 1: pop\n 2: top\n 3: isEmpty\n 4: size\n 5: exit\n");
        scanf("%d", &input);

        switch (input)
        {
        case POST:
            printf("Please enter a number you want to push: ");
            int number = 0;
            scanf("%d", &number);
            push(number);
            printStack();
            break;

        case POP:
            int popped_number = pop();
            popped_number != -1 ? ("%d is popped from the stack.\n", popped_number) : "";
            printStack();
            break;
        
        case TOP:
            int top_element = top();
            top_element != -1 ? ("%d is the top element on the stack.\n", top_element) : "";
            printStack();
            break;
        
        case IS_EMPTY:
            ( isEmpty() == true ) ? printf("Stack is empty.\n") : printf("Stack is not empty.\n");
            printStack();
            break;
        
        case SIZE:
            printf("Size of the stack is %d.\n", size());
            printStack();
            break;

        case EXIT:
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

bool isEmpty(){
    if(next == -1){
        return true;
    }
    return false;

}

int size(){
    return next + 1;
}

void push(int number){
    if(next == capacity -1 ){
        printf("The stack is full.\n");
        return;
    }

    stack[++next] = number;
    return;
}

int pop(){
    if(next == -1){
        printf("Stack is empty. can not be popped.\n");
        return -1;
    }
    int number = stack[next];
    next--;
    return number;
}

void printStack(){
    int i = next;
    while(i >= 0){
        printf("|%3s%d%3s|\n"," ", stack[i], " ");
        i--;
    }
    printf("_______\n");
    return;
}

int top(){
    if(next == -1){
        printf("Stack is empty.\n");
        return -1;
    }

    return stack[next];
}

