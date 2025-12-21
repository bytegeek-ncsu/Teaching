/**
 * @file InsertionSort.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

using namespace std;

void insertionSort(int myArray[], int size){
    
    for (int i = 1; i < size; i++){
        int temp = myArray[i];
        int j = i-1;

        while(j > -1 && temp < myArray[j]){
            myArray[j+1] = myArray[j];
            myArray[j] = temp;
            j--; 
        }
        
    }

}

int main() {
    
    int myArray[] = {6,4,2,1,5,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    insertionSort(myArray, size);


    for (auto value : myArray)  
        cout << value << " ";
    

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    return 0;
}