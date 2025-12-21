#include<stdio.h>
#include<stdbool.h>


int main(){

    int number;
    bool done = false;


    printf(" Please enter a number between 0 and 99 \n");

    scanf("%d", &number);

    while(!done){

        printf("%d\n", number);

        int first_digit = number%10;
        int second_digit = number/10;

        if (first_digit == second_digit)
            done = true;
        number--;

    }
    
    return 0;
}