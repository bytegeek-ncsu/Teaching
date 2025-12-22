/**
 * @file mergeSort.cc
 * @Shak(shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

using namespace std;


void merge(int myArray[], int leftIndex, int midIndex, int rightIndex){
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    //Now create left subArray and copy 
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i=0; i<leftArraySize; i++)
        leftArray[i] = myArray[leftIndex+i];
    for (int j=0; j<rightArraySize; j++)
        rightArray[j] = myArray[midIndex+1+j];

    //Now will compare the elements from i and j index of subarrays and which ever is smaller copy into orginal array
    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize){

        if (leftArray[i] <= rightArray[j]){
            myArray[index] = leftArray[i];
            i++;
        }else {
            myArray[index] = rightArray[j];
            j++;
        }
        index++; //move the index for next slot to copy in original array
    }

    //Now one of the array might have left over elements we need to copy them to original array

    while (i < leftArraySize){
        myArray[index] =leftArray[i];
        ++i;
        ++index;
    }

    while (j < rightArraySize){
        myArray[index] = rightArray[j];
        ++j;
        ++index;
    }
}

void mergeSort(int myArray[], int leftIndex, int rightIndex){
    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex+ (rightIndex-leftIndex)/2;
    mergeSort(myArray, leftIndex, midIndex);
    mergeSort(myArray, midIndex+1, rightIndex);
    merge(myArray, leftIndex, midIndex, rightIndex);
}
 
 
int main() {
    
    //int myArray[] = {1,3,7,8,2,4,5,6};
    int myArray[] = {3,1,4,2};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    //int midIndex = (size / 2) - 1;


    mergeSort(myArray, leftIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8 
        
     */

}