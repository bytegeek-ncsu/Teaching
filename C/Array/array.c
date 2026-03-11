#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * In this example we are building a array a data strcture similar like STL array data structure in C++
 */

struct Array{

    int *base;
    int size; // maximum capacity of the array
    int length; //number of the elements currently in the array

};

struct Array1{
    int A[10];
    int size;
    int length;

};



void display(struct Array *);
void display1(struct Array1 *);
void append(struct Array *, int);
void insert(struct Array *, int, int);
int delete(struct Array *, int);
int search(struct Array *, int);
int binSearch(struct Array *, int, int, int);
int get(struct Array *, int);
void set(struct Array *, int, int);
int max(struct Array);
int min(struct Array);
void reverse(struct Array *);
void inPlaceReverse(struct Array*);
int isSorted(struct Array);
void arrangeSides(struct Array1 *);
struct Array1 * merge(struct Array1 *, struct Array1 *);
struct Array1 * union1(struct Array1 *, struct Array1 *);
struct Array1 * intersection(struct Array1 *, struct Array1 *);
struct Array1 * difference(struct Array1 *, struct Array1 *);
void findingMissingElement(struct Array1 *);
void findingMissingElement1(struct Array1 *);
void findingMissingElement2(struct Array1 *, int);
void findingDuplicateSorted(struct Array1 *);
void findingDuplicateSorted1(struct Array1 *, int);
void findingDuplicateUnSorted(struct Array1 *);
void findingDuplicateUnSorted1(struct Array1 *, int);
void findingPairUnsorted(struct Array1 *, int);
void findingPairUnSorted1(struct Array1 *, int, int);
void findingPairSorted(struct Array1 *, int);





int main(){

    struct Array array;

    printf(" Enter the size of the array \n");
    scanf("%d", &array.size);

    array.base = (int *)malloc(array.size * sizeof(int));

    for (int i = 0; i < 5; i++)
        array.base[i] = i * 5 + 5;
    array.length = 5;

    append(&array, 40);

    insert(&array, 4, 50);
    

    display(&array);

    printf("The value deleted is :: %d \n", delete(&array, 2));

    display(&array);

    inPlaceReverse(&array);

    display(&array);

    if (binSearch(&array, 0, array.length-1, 20)){
        printf(" Hey I found the key 20 in the array \n");
    }

    if (!binSearch(&array, 0, array.length-1, 35)){
        printf(" Hey I didn't found  the key 35 in the array \n");
    }

    struct Array1 a = {{-1, 3, -2, 4, -5}, 10, 5};
    arrangeSides (&a);
    display1(&a);

    struct Array1 a1 = {{3,4,5,6,10},10,5};
    struct Array1 a2 = {{2,4,5,7,12},10,5};

    struct Array1 *a3;
    a3 = difference(&a1, &a2);

    display1(a3);

    //struct Array1 a4 = {{3,7,4,9,12,6,1,11,2,10},10,10};
    struct Array1 a4 = {{1,3,4,5,6,8,9,10,12,14},10,10};
    findingPairSorted(&a4,10);
   

    return 0;
}

void display (struct Array *a){
    int len = a->length;
    printf("Array Elements are :: ");
    for (int i=0; i<len; i++)
        printf ("%d ", a->base[i]);
    printf("\n");
}

void display1 (struct Array1 *a){
    int len = a->length;
    printf("Array Elements are :: ");
    for (int i=0; i<len; i++)
        printf ("%d ", a->A[i]);
    printf("\n");
}

void append(struct Array *arr, int key){
    if ( arr->length >= arr->size){
        printf("There is no room to add any elements in the array\n");
        return;
    }

    arr->base[arr->length] = key;
    arr->length++;
}

void insert(struct Array *arr, int index, int key){

    if (index >= arr->length){
        printf("There is no room to add a new element \n");
        return;
    }

    for (int i=arr->length; i>index; i--)
        arr->base[i] = arr->base[i-1];
    arr->base[index] = key;
    arr->length++;

}
int delete(struct Array *arr, int index){
    if (arr->length == 0 && index >= arr->length){
        printf("Array is empty and nothig to delete or index out of range \n");
        return -1;
    }

    int value = arr->base[index];

    for (int i=index; i< arr->length; i++)
        arr->base[i] = arr->base[i+1];
    arr->length--;
    return value;
}

    
int search(struct Array *arr, int key){
    for (int i=0; i < arr->length; i++){
        if(arr->base[i] == key)
            return 1;
    }
    return 0;
    
    
}
int binSearch(struct Array *array, int low, int high, int key){

    if (low > high)
        return 0;
    
    int mid = floor((low+high)/2);
    if (array->base[mid] == key){
        return 1;
    }else if (array->base[mid] > key){
        binSearch(array, low, mid-1, key);
    }else{
        binSearch(array, mid+1, high, key);
    }
    return -1;

}

int get(struct Array *a, int index){

    if(index < 0 || index >= a->length){
        printf("Array out of bound error \n");
        return -1;
    }
    return a->base[index];
}

void set(struct Array *array, int index, int key){
    if(index < 0 || index >= array->length){
        printf("Array out of bound error \n");
        return;
    }
    for (int i = array->length; i > index; i--)
        array->base[i] = array->base[i-1];
    array->base[index] = key;
}

int max(struct Array a){
    if (a.length == 0){
        printf("ERROR::Array is empty \n");
        return -1;
    }
    int max = a.base[0];
    for (int i=0; i<a.length; i++){
        if (a.base[i] > max)
            max = a.base[i];
    }
    return max;
}

int min(struct Array a){
    if (a.length == 0){
        printf("ERROR::Array is empty \n");
        return -1;
    }
    int min = a.base[0];
    for (int i=0; i<a.length; i++){
        if (a.base[i] < min)
            min = a.base[i];
    }
    return min;
}

void reverse(struct Array *a){
    int *aux_array;

    aux_array = (int*) malloc(a->length*sizeof(int));

    for (int i = a->length-1, j = 0; i >= 0; i--, j++)
        aux_array[j] = a->base[i];

    for (int i = 0; i < a->length; i++)
        a->base[i] = aux_array[i];
}

void inPlaceReverse(struct Array *a){

    for (int j = a->length-1, i = 0; i < j; i++, j--){
        int temp = a->base[i];
        a->base[i] = a->base[j];
        a->base[j] = temp;
    }


}

int isSorted(struct Array a){
    for (int i = 0; i < a.length-1; i++){
        if ( a.base[i] > a.base[i+1])
            return 0;
    }
    return 1;
}

void arrangeSides(struct Array1 *a){
    int i = 0;
    int j = a->length - 1;
    while (i < j){
        while (a->A[i] < 0) ++i;
        while (a->A[j] >= 0) --j;
        if (i < j){
            int temp = a->A[i];
            a->A[i] = a->A[j];
            a->A[j] = temp;
        }
    }
}

struct Array1 * merge(struct Array1 *a1, struct Array1 *a2){

    struct Array1 *a3 = (struct Array1*) malloc(sizeof(struct Array1));
    a3->size = 10;

    int i = 0, j = 0, k = 0;

    //This version allows duplicate entries.
    while (i < a1->length && j < a2->length){
        if(a1->A[i] <= a2->A[j]){
            a3->A[k++] = a1->A[i];
            ++i;
        }else{
            a3->A[k++] = a2->A[j];
            ++j;
        }

    }

    for (; i < a1->length; i++)
        a3->A[k++] = a1->A[i];
    
    for (; j < a2->length; j++)
        a3->A[k++] = a2->A[j];
    a3->length = k;
    return a3;
    

}

struct Array1 * union1(struct Array1 *a1, struct Array1 *a2){

    struct Array1 *a3 = (struct Array1*) malloc(sizeof(struct Array1));
    a3->size = 10;

    int i = 0, j = 0, k = 0;

    //This version doest not allow any duplicate entries.

    while (i < a1->length && j < a2->length){
        if(a1->A[i] < a2->A[j]){
            a3->A[k++] = a1->A[i];
            ++i;
        }else if(a2->A[j] < a1->A[i]){
            a3->A[k++] = a2->A[j];
            ++j;
        }else{
            a3->A[k++] = a1->A[i];
            ++i;
            ++j;
        }

    }

    for (; i < a1->length; i++)
        a3->A[k++] = a1->A[i];
    
    for (; j < a2->length; j++)
        a3->A[k++] = a2->A[j];
    a3->length = k;
    return a3;
    

}

struct Array1 * intersection(struct Array1 *a1, struct Array1 *a2){

    struct Array1 *a3 = (struct Array1*) malloc(sizeof(struct Array1));
    a3->size = 10;

    int i = 0, j = 0, k = 0;

    //Intersection set operation. Common two array

    while (i < a1->length && j < a2->length){
        if(a1->A[i] < a2->A[j]){
            ++i;
        }else if(a2->A[j] < a1->A[i]){
            ++j;
        }else{
             a3->A[k++] = a2->A[i];
            ++i;
            ++j;
        }

    }
    a3->length = k;
    return a3;
    

}

struct Array1 * difference(struct Array1 *a1, struct Array1 *a2){

    struct Array1 *a3 = (struct Array1*) malloc(sizeof(struct Array1));
    a3->size = 10;

    int i = 0, j = 0, k = 0;

    //difference A-B set operation. Common two array

    while (i < a1->length && j < a2->length){
        if(a1->A[i] != a2->A[j]){
            a3->A[k++] = a1->A[i];
            ++i;
            ++j;
        }else{
            ++i;
            ++j;
        }

    }
    a3->length = k;
    return a3;
    

}

//In this case the array is a sequence of numbers starting at random number
//We have multiple missing elements
void findingMissingElement(struct Array1 *a1){
    int low = a1->A[0];
    int diff = low - 0;

    for (int i = 0; i < a1->length; i++){
        if (a1->A[i] - i != diff){
            printf("Missing Element is: %d\n",i+diff );
            diff++;
        }
    }

}

//In this case the array is a sequence of numbers starting at random number
void findingMissingElement1(struct Array1 *a1){
    int low = a1->A[0];
    int diff = low - 0;

    for (int i = 0; i < a1->length; i++){
        if (a1->A[i] - i != diff){
            while (a1->A[i] - i != diff){
                printf("missing Element :%d\n", i+diff);
                diff++;
            }
        }
    }

}

//In this case the array is a sequence of numbers starting at random number
void findingMissingElement2(struct Array1 *a1, int max){

    int *H;
    H = (int*) malloc(max*sizeof(int));
    for (int i= 0; i < max; i++)
        H[i] = 0;

    for (int i = 0; i < a1->length; i++)
        H[a1->A[i]]++;

    for (int i= 1; i < max; i++){
        if (H[i] == 0)
            printf("Missing element is::%d\n", i);
    }
}

void findingDuplicateSorted(struct Array1 *a){
    int lastDuplicate = 0;
    int count = 1;
    for(int i=0; i<a->length-1; i++){
        if (a->A[i] == a->A[i+1]){
            lastDuplicate = a->A[i];
           while (a->A[i+1] == lastDuplicate ){
            count++;
            i++;
           }

           printf("Duplicate is: %d and count is: %d\n", lastDuplicate,count);
        }
        count = 1;
    }

}
void findingDuplicateSorted1(struct Array1 *a1, int max){
    int *H;
    H = (int*) malloc(max*sizeof(int));
    for (int i= 0; i < max; i++)
        H[i] = 0;

    for (int i = 0; i < a1->length; i++)
        H[a1->A[i]]++;

    for (int i= 1; i < max; i++){
        if (H[i] > 1)
            printf("Duplicate element is::%d count is : %d\n", i, H[i]);
    }
}
void findingDuplicateUnSorted(struct Array1 *a){
    for (int i=0; i<a->length-1; i++){
        int count = 1;
        if (a->A[i] != -1){
            for (int j = i+1; j<a->length; j++){
                if (a->A[i] == a->A[j]){
                    count++;
                    a->A[j] = -1;
                }
            }
            if (count>1)
                printf("Duplicate from unsorted: %d count is: %d\n", a->A[i], count);
        }

    }

}
void findingDuplicateUnSorted1(struct Array1 *a1, int max){
    int *H;
    H = (int*) malloc(max*sizeof(int));
    for (int i= 0; i < max; i++)
        H[i] = 0;

    for (int i = 0; i < a1->length; i++)
        H[a1->A[i]]++;

    for (int i= 1; i < max; i++){
        if (H[i] > 1)
            printf("Duplicate element is::%d count is : %d\n", i, H[i]);
    }
}
void findingPairUnsorted(struct Array1 *a, int sum){
    for (int i = 0; i < a->length-1; i++){
        for (int j = i+1; j < a->length; j++)
            if (a->A[i]+a->A[j] == sum){
                printf("The pair of elements is: %d, %d\n", a->A[i],a->A[j] );
            }
    
    }

}
void findingPairUnSorted1(struct Array1 *a1,int max, int sum){
    int *H;
    H = (int*) malloc(max*sizeof(int));
    for (int i= 0; i < max; i++)
        H[i] = 0;

    for (int i = 0; i < a1->length; i++){
        if ((sum - a1->A[i] > 0) && (H[sum - a1->A[i]] != 0)){
            printf("Find the pairs %d, %d \n", sum-a1->A[i], a1->A[i]);
        }
        H[a1->A[i]]++;
    }

    
}
void findingPairSorted(struct Array1 *a1, int sum){
    int i=0, j=a1->length-1;

    while (i<j){
        if(a1->A[i]+a1->A[j]> sum)
            --j;
        else if(a1->A[i]+a1->A[j]<sum)
            ++i;
        else{
            printf("We find the pairs %d, %d\n", a1->A[i],a1->A[j]);
            ++i;
            ++j;
        }
    }

}


