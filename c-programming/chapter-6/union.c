#include <stdio.h>
#include <stdint.h>

union padding{
   long a;
   char b;
   int c;
};

int main(){
   union padding node;
   printf("size : %zu\n", sizeof(node));
   printf("Address of node.a: %lu\n", (uintptr_t)&node.a);

   printf("Address of node.b: %lu\n", (uintptr_t)&node.b);

   printf("Address of node.c: %lu\n", (uintptr_t)&node.c);
   return 0;
}