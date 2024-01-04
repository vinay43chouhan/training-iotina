#include "stack.h"

#include <stdbool.h>

int *stack = NULL;
int next = -1;
int capacity = 0;

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

