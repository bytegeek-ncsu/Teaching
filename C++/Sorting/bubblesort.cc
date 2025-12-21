/**
 * @file bubblesort.cc
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

void bubbleSort(int myArray[], int size){
    int done = 0;
    int swapped = 0;
    int outerLoopIndex = size-1;

    while(!done){
        swapped = 0;
        for (int i=0; i<outerLoopIndex; i++){
            if(myArray[i]> myArray[i+1]){
                int temp = myArray[i];
                myArray[i] = myArray[i+1];
                myArray[i+1] = temp;
                swapped = 1;
            }

        }

        --outerLoopIndex;
        if( !swapped || !outerLoopIndex)
            done = 1;

    }

}

int main() {
    
    int myArray[] = {6,4,2,1,5,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray)  
        cout << value << " ";
    

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    return 0;
}