#include<stdio.h>

int main(){
    float fahrenheit;
    float celsius;
    char choice;
    float lower, upper, step;
    printf("Enter upper value of fahrenheit temperature: \n");
    scanf("%f", &upper);
    printf("Enter lower value of fahrenheit temperature: \n");
    scanf("%f", &lower);
    printf("Enter step value for next fahrenheit temperature: \n");
    scanf("%f", &step);

    if(step==0){
        printf("Please enter step's value greater then zero.");
        return 0;
    }
    getchar();
    printf("want to convert upper to lower: y/n \n");
    choice = getchar();
    if (choice == 'y'){
        for(fahrenheit = upper; fahrenheit>=lower; fahrenheit = fahrenheit-step){
            celsius = 5*(fahrenheit-32)/9;
            printf("%f\t%f\n", fahrenheit, celsius);
        }
    }else{
        for(fahrenheit = lower; fahrenheit<=lower; fahrenheit = fahrenheit+step){
            celsius = 5*(fahrenheit-32)/9;
            printf("%f\t%f\n", fahrenheit, celsius);
        }
    }


    return 0;
    
}