/**
 * @file selection_sort.cc
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

void selectionSort(int myArray[], int size){
    
    for (int i = 0; i < size; i++){
        int minIndex = i;
        for (int j = i+1; j < size; j++){
            if(myArray[minIndex]>myArray[j])
                minIndex = j;
        }

        int temp = myArray[i];
        myArray[i] = myArray[minIndex];
        myArray[minIndex] = temp;

    }

}

int main() {
    
    int myArray[] = {6,4,2,1,5,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    selectionSort(myArray, size);


    for (auto value : myArray)  
        cout << value << " ";
    

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    return 0;
}