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



int main(){

    demo1();

    return 0;
}