/**
 * In this code we will demo vector functions which are not used in array demo
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> &data){
    for_each(data.begin(), data.end(), [](int x){cout<<x<<" ";});
    cout<<endl;
}

void init_demo(){
    vector<int> test = {1, 2, 3, 4, 5};

    //vector<int> test1;
    
    //test1[2] = 5;  this is illegal.
    //we  create vector using constructor
    vector<int> test1(5, 1);
    cout<<"test1 size::"<<test1.size()<<" test1 capacity::"<<test1.capacity()<<endl;
    print(test);
    
    print(test1);


}

void demo2(){
    vector<int> test = {2, 15, 8, 19, 12};

    print(test);

    sort(test.begin(), test.end());

    print(test);
    auto it = test.begin();
    while(it != test.end()){
        *it = *it*2;
        ++it;
    }
    print(test);
}

void demo3(){
    vector<int> test = {2, 15, 8, 19, 12};
    vector<int> test1 (5, 5);

    copy(test1.begin(), test1.end(), back_inserter(test));
    print(test);
    print(test1);

    copy_if(test1.begin(), test1.end(), back_inserter(test), [] (int x){ return x % 2 == 0; } );
    print(test);
    print(test1);
    
}

int main(){
    init_demo();
    demo2();
    demo3();

    return 0;
}