/**
 * This code demo array functionalities including init, sort, fill, count and count_if etc
 */
#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

void init_demo(){
    array<int, 8> nums = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int num: nums)
        cout<<num<<" ";
    cout<<endl;

    array<int, 5> test;


     for (int num: test)
        cout<<num<<" ";
    cout<<endl;

    test.fill(10);

     for (int num: test)
        cout<<num<<" ";
    cout<<endl;

}

void sort_demo(){
    array<int, 5> test = {6, 3, 77, 17, 90};

   sort(test.begin(), test.end());

    for (int num: test)
        cout<<num<<" ";
    cout<<endl;
}

void count_demo(){
    array<int, 5> test = {1, 2 ,1 ,3, 1};

    int num = count(test.begin(), test.end(), 1);
    cout<<" Number of 1 occurences : "<<num<<endl;
}

void count_if_demo(){
    array<int, 6> test = {1 ,2 ,3, 4, 5 ,6};

    int num = count_if(test.begin(), test.end(), [] (int x){ return x % 3 == 0;});
    cout<<num<<endl;
}

int main(){

    init_demo();
    sort_demo();
    count_demo();
    count_if_demo();
    return 0;
}


