#include<stdio.h>



int main(){
    int hours;
    int minutes;
    int seconds;
    int time;
    printf("Hello World");

    printf("Please enter the time:\n");

    scanf("%d", &time);

    hours = time/3600;

    printf("Time in hours %d \n ", hours);


    return 0;
}