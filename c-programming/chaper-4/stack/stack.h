#ifndef STACK 
#define STACK

#include <stdbool.h>
#include <stdio.h>

extern int *stack;
extern int capacity;
extern int next;

void push(int number);
int pop();
int top();
bool isEmpty();
int size();
void printStack();

#endif