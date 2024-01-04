#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
/*
struct point_without_typedef
{
    int x_coordinate;
    int y_coordinate;
};
*/

typedef struct
{
    int x_coordinate;
    int y_coordinate;
} point;

static point* array;
static int index = 0;

// Passing structure to function
void printPoint(point p); // pri nt the giving point
float distanceBWPoint(point p1, point p2); // find the distance b/w point p1 to p2
point *arrayOfStructure(point p); // create a array of points
point* maxOfPoints(point *p1, point *p2);


/*void printPoint(struct point_without_typedef p);*/

int main(){
    /*
    struct point_without_typedef p1;
    struct point_without_typedef p2;

    printf("Enter the x coordinate of p1: ");
    scanf("%d", &p1.x_coordinate);
    printf("Enter the y coordinate of p2: ");
    scanf("%d", &p1.y_coordinate);

    printPoint(p1);

    */
     // Allocate memory for the static array
     char yes = '\0';
    array = (point*)malloc(SIZE * sizeof(point));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    point p1;
    point p2;

    printf("Enter the x coordinate of p1: ");
    scanf("%d", &p1.x_coordinate);
    printf("Enter the y coordinate of p1: ");
    scanf("%d", &p1.y_coordinate);

    printf("Enter the x coordinate of p2: ");
    scanf("%d", &p2.x_coordinate);
    printf("Enter the y coordinate of p2: ");
    scanf("%d", &p2.y_coordinate);

    printPoint(p1);
    printPoint(p2);

    printf("Distance: %f", distanceBWPoint(p1, p2));

    arrayOfStructure(p1);
    arrayOfStructure(p2);

    printf("\nPrinting array items: ");
    for(int i = 0; i < index; i++){
        printPoint(array[i]);
    }

    printf("\nWant to check which pointer is greater: Enter y/n");
    getchar();
    scanf("%c", &yes);
    if(yes == 'y'){
        point* p = maxOfPoints(&p1, &p2);
        // printf("Point is: (%d, %d)", p->x_coordinate, p->y_coordinate);
    }
    return 0;

}

/*
void printPoint(struct point_without_typedef p){
    printf("point is (%d, %d)\n", p.x_coordinate, p.y_coordinate);
    return 0;
}
*/

void printPoint(point p){
    printf("point is (%d, %d)\n", p.x_coordinate, p.y_coordinate);
    return;
}

float distanceBWPoint(point p1, point p2){
    int number = ((p1.x_coordinate * p1.x_coordinate - p2.x_coordinate * p2.x_coordinate) + (p1.y_coordinate * p1.y_coordinate - p2.y_coordinate * p2.y_coordinate));
    if(number < 0){
        number = -number;
    }
    return sqrt((double)number);
}

point* arrayOfStructure(point p){
    array[index++] = p;
    return array;
}


point* maxOfPoints(point *p1, point *p2){
    int sign = p1->x_coordinate - p2->x_coordinate + p1->y_coordinate - p2->y_coordinate;
    if(sign > 1){
        printf("Point (%d, %d) is greater then the (%d, %d).\n", p1->x_coordinate, p1->y_coordinate, p2->x_coordinate, p2->y_coordinate);
        return p1;
    }else if(sign < 1){
        printf("Point (%d, %d) is greater then the (%d, %d).\n", p2->x_coordinate, p2->y_coordinate, p1->x_coordinate, p1->y_coordinate);
        return p2;
    }else{
        printf("Both pointer's are equal.\n");
        return p1;
    }
}