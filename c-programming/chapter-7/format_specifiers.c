#include <stdio.h>

int main(){
    int d = 23;
    float f = 2.57238;
    printf("%d\n",d);
    printf("%10d\n",d);
    printf("%-5d%s\n", d, "hi");
    // printf("%-3.5d%s\n", d, "hello");
    printf("%f\n", f);
    printf("%0.3f\n", f);
    printf("%0.11f\n", f);
    return 0;
}