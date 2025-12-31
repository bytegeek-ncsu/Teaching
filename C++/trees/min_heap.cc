/*
* This is just a opposite of maxHeap implementation.
*/
#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
    private:
        vector<int> minHeap;
    
        int leftChild(int parentIndex){
            return 2*parentIndex;
        }

        int rightChild(int parentIndex){
            return 2*parentIndex+1;
        }

        int parent(int childIndex){
            return childIndex/2;
        }

        void swap(int index1, int index2){
            int temp = minHeap[index1];
            minHeap[index1] = minHeap[index2];
            minHeap[index2] = temp;
        }

    public:
        MinHeap(){
            minHeap.push_back(-1); //Pushing the dummy value in the first slot.
        }
        void insert(int);
        int remove();
        void sinkDown(int);
        void print();


};

void MinHeap::insert(int value){
    //push the value to the end of the vector
    minHeap.push_back(value);
    //CurrentIndex will be heap.size. Remember first slot is empy
    int currentIndex = minHeap.size()-1;
    //After inserting the value we want to heapfy the struture. How check current value is greater than the parent. if so moveup.
    //Do this until currentIndex value is not greate than the parent or currentIndex reaches root of the tree.
    while(currentIndex > 1 && minHeap[currentIndex] < minHeap[parent(currentIndex)]){
        swap(currentIndex, parent(currentIndex));
        currentIndex = parent(currentIndex);
    }
}

int MinHeap::remove(){
    //In the case remove always remove the top of tree(root). Then make the tree complete by moving the last element to root.
    //After moving make the sure the tree is maxheap. We need to sinkdown the the moved value to the appropriate location.
    //Three cases. 1. empty. 2. one item 3. 2 or more items in the heap.
    int minValue = 0;
    if (minHeap.size() == 1) return -1; //heap is empty;
    else if(minHeap.size() == 2){
        minValue = minHeap[1];
        minHeap.pop_back();
    }else{
        minValue = minHeap[1];
        minHeap[1] = minHeap.back();
        minHeap.pop_back();
        sinkDown(1);
    }
    return minValue;
}

void MinHeap::sinkDown(int index){
    //assign current index as maxIndex
    int minIndex = index;
    while(true){
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);
        //Here we check whether leftIndex is valid index or not. and then check if it is greater than the ma
        if (leftIndex < minHeap.size() && minHeap[leftIndex] < minHeap[minIndex])
            minIndex = leftIndex;
        if (rightIndex < minHeap.size() && minHeap[rightIndex] < minHeap[minIndex])
            minIndex = rightIndex;

        if (minIndex != index){
            swap(minIndex, index);
            index = minIndex;
        }else{
            return;
        }
    }
}

void MinHeap::print(){
    cout<<"MaxHeap items are:: ";
    for (int i=1; i<minHeap.size(); i++)
        cout<<minHeap[i]<<" ";
    cout<<endl;
}

int main(){
    MinHeap minHeap;
    
    minHeap.insert(99);
    minHeap.insert(72);
    minHeap.insert(61);
    minHeap.insert(58);
    minHeap.insert(100);
    minHeap.insert(65);

    minHeap.print();

    minHeap.remove();

    minHeap.print();

    return 0;
}