#include <stdio.h>
#include <stdlib.h>

/**
 * In this example we are building a array a data strcture similar like STL array data structure in C++
 */

struct Array{

    int *base;
    int size; // maximum capacity of the array
    int length; //number of the elements currently in the array

};

void display(struct Array *);


int main(){

    struct Array array;

    printf(" Enter the size of the array \n");
    scanf("%d", &array.size);

    array.base = (int *)malloc(array.size * sizeof(int));

    for (int i = 0; i < 5; i++)
        array.base[i] = i * 5 + 5;
    array.length = 5;

    display(&array);

    return 0;
}

void display (struct Array *a){
    int len = a->length;
    printf("Array Elements are :: ");
    for (int i=0; i<len; i++)
        printf ("%d ", a->base[i]);
    printf("\n");
}