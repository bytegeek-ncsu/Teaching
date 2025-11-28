#include<iostream>
#include "IntArray.h"

IntArray::IntArray(const IntArray &copy){
    int length = copy.size;
    array = new int[length];
    for (int i=0; i<length; i++){
        array[i] = copy.array[i];
    }
}

/**
 * Assignment operator is little different than copy constructor
 * 1.first check are they reference same pointer so just return *this
 * 2. check if the members are already initialized then clean up the member in this case array
 * 3. Now initialize the array 
 * 
 * @param rhs 
 * @return IntArray& 
 */

IntArray&IntArray::operator=(const IntArray &rhs){
    if(this == &rhs)
        return *this;
    if(array)
        delete array;
    int length = rhs.size;
    array = new int[length];
    for (int i=0; i< length; i++)
        array[i] = rhs.array[i];
    return *this;

}

IntArray IntArray::operator + (const IntArray &rhs) const{
    IntArray result(size);
    int i=0;
    for (; i<rhs.size; i++)
        result.array[i] = array[i]+rhs.array[i];
    //Suppose rhs lenght is smaller than current array size
    for (; i<size; ++i)
        result.array[i] = array[i];
    return result;

}

int& IntArray::operator[] (int index){
    return array[index];
}


int main(){

    IntArray array(100);

    array[50] = 100;

    IntArray second = array;
    std::cout<<"Array Index 50 is::"<<array[50]<<std::endl;

    second[50] = 500;
    std::cout<<"Second Array Index 50 is::"<<second[50]<<std::endl;

    return 0;
}