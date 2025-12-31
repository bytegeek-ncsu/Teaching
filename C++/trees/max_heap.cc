/**
 * This examples demonstrates max heap, which generally used as a  priority queue
 * The paraent is greater than its children. In this implementation we leave the first slot empty(-1).
 */

#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
    private:
        vector<int> maxHeap;
    
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
            int temp = maxHeap[index1];
            maxHeap[index1] = maxHeap[index2];
            maxHeap[index2] = temp;
        }

    public:
        MaxHeap(){
            maxHeap.push_back(-1); //Pushing the dummy value in the first slot.
        }
        void insert(int);
        int remove();
        void sinkDown(int);
        void print();


};

void MaxHeap::insert(int value){
    //push the value to the end of the vector
    maxHeap.push_back(value);
    //CurrentIndex will be heap.size. Remember first slot is empy
    int currentIndex = maxHeap.size()-1;
    //After inserting the value we want to heapfy the struture. How check current value is greater than the parent. if so moveup.
    //Do this until currentIndex value is not greate than the parent or currentIndex reaches root of the tree.
    while(currentIndex > 1 && maxHeap[currentIndex] > maxHeap[parent(currentIndex)]){
        swap(currentIndex, parent(currentIndex));
        currentIndex = parent(currentIndex);
    }
}

int MaxHeap::remove(){
    //In the case remove always remove the top of tree(root). Then make the tree complete by moving the last element to root.
    //After moving make the sure the tree is maxheap. We need to sinkdown the the moved value to the appropriate location.
    //Three cases. 1. empty. 2. one item 3. 2 or more items in the heap.
    int maxValue = 0;
    if (maxHeap.size() == 1) return -1; //heap is empty;
    else if(maxHeap.size() == 2){
        maxValue = maxHeap[1];
        maxHeap.pop_back();
    }else{
        maxValue = maxHeap[1];
        maxHeap[1] = maxHeap.back();
        maxHeap.pop_back();
        sinkDown(1);
    }
    return maxValue;
}

void MaxHeap::sinkDown(int index){
    //assign current index as maxIndex
    int maxIndex = index;
    while(true){
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);
        //Here we check whether leftIndex is valid index or not. and then check if it is greater than the ma
        if (leftIndex < maxHeap.size() && maxHeap[leftIndex] > maxHeap[maxIndex])
            maxIndex = leftIndex;
        if (rightIndex < maxHeap.size() && maxHeap[rightIndex] > maxHeap[maxIndex])
            maxIndex = rightIndex;

        if (maxIndex != index){
            swap(maxIndex, index);
            index = maxIndex;
        }else{
            return;
        }
    }
}

void MaxHeap::print(){
    cout<<"MaxHeap items are:: ";
    for (int i=1; i<maxHeap.size(); i++)
        cout<<maxHeap[i]<<" ";
    cout<<endl;
}

int main(){
    MaxHeap maxHeap;
    
    maxHeap.insert(99);
    maxHeap.insert(72);
    maxHeap.insert(61);
    maxHeap.insert(58);
    maxHeap.insert(100);
    maxHeap.insert(65);

    maxHeap.print();

    maxHeap.remove();

    maxHeap.print();

    return 0;
}