/**
 * @file quick_sort.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>

using namespace std;


void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}


int pivot(int myArray[], int startIndex, int endIndex){
    int pIndex = startIndex;
    int swapIndex = startIndex;

    for (int i=pIndex+1; i<=endIndex; i++){
        if(myArray[pIndex] > myArray[i]) {
            swapIndex++;
            swap(myArray, swapIndex, i);
        }
    }
  
    swap(myArray, swapIndex, pIndex);
    pIndex = swapIndex;

    return pIndex;

}	

void quickSort(int myArray[], int leftIndex, int rightIndex){
    if (leftIndex >= rightIndex) return;
    int pIndex = pivot(myArray, leftIndex, rightIndex);
    quickSort(myArray, leftIndex, pIndex-1);
    quickSort(myArray, pIndex+1, rightIndex);
}



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    quickSort(myArray, 0, size-1);

    //cout << "Returned Index: " << returnedIndex << "\n\n";

    for (auto value : myArray) {
        cout << value << " ";
    }

    
}