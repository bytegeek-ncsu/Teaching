/**
 * This code demonstrates simple iterator functionalities and also different types of iterator
 */

#include<iostream>
#include<vector>

using namespace std;

// This function demo simple iterator functionalities. iterator is pretty much like pointer. you can dereferemce increment, move forward etc;
void demo1(){

    vector<int> test = {1, 2, 3, 4, 5};

    auto it  = test.begin();

    cout<<*it<<endl;

    cout<<*(it+1)<<endl;

    it +=2;

    cout<<*it<<endl;

    vector<int> test1(10, 20);

    it = test1.begin();
    while (it != test1.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;

}

void demo2(){
    vector<int> test = {1, 2, 3, 4, 5};

    vector<int>::const_iterator it = test.cbegin();

    while (it != test.cend()){
        cout<<*it<< " ";
        ++it;
        //*it = 100; not acceptable since it is a const iterator
    }
    cout<<endl;
}

void demo3(){
    vector<int> test = {1, 2, 3, 4, 5};

    vector<int>::reverse_iterator it = test.rbegin();

    while (it != test.rend()){
        cout<<*it<< " ";
        ++it;
        //*it = 100; not acceptable since it is a const iterator
    }
    cout<<endl;
}



int main(){

    demo1();
    demo2();
    demo3();

    return 0;
}