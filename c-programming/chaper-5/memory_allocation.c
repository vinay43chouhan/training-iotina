#include <stdio.h>

#define MAXSIZE 1000

static char storage[MAXSIZE];
static char* next_free_location = storage;

char* alloc(int num_space){
    if(storage + MAXSIZE - next_free_location >= num_space){
        printf("Memory is avaiable.\n");
        next_free_location += num_space;
        return next_free_location-num_space;
    }else{
        printf("Memory is not present.\n");
        return NULL;
    }

}

char* freeAll(int n){
    return next_free_location - n;
}

int main(){
    int num_space = 0;
    int free = 0;

    while(1){
        printf("Enter +ve number of byte you want to allocate else enter -1 to exit: ");
        scanf("%d", &num_space);
        getchar();
        if(num_space == -1){
            break;
        }
        alloc(num_space);
        printf("Enter +ve number of byte you want to deallocate else enter -1 to exit: ");
        scanf("%d", &free);
        getchar();
        if(free == -1){
            break;
        }
        freeAll(free);
        
    }
    

    

    return 0;
}