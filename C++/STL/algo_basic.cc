/**
 * In this example I will introduce algorithm methods which are in common
 */
#include<algorithm>
#include <iostream>
#include <vector>
#include <list>
#include<cctype>

using namespace std;

void find_demo(){
    cout<<"********Find Demo************"<<endl;

    vector<int> test = {10, 20, 30, 40, 50};

    auto it = find(test.begin(), test.end(), 30);

    if (it != test.end())
        cout<<"Found the given number: "<<*it<<endl;

}

//This function demo the count algo

void count_demo(){
    cout<<"********count Demo************"<<endl;

    vector<int> test = {10, 20, 10, 30, 10, 40, 50};

    int count1 = count(test.begin(), test.end(), 10);

    cout<<"Number of 10's occurences::"<<count1<<endl;

}

void count_if_demo(){
    cout<<"********count_if Demo************"<<endl;

    vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count1 = count_if(test.begin(), test.end(), [] (int x) {return x%2 == 1;}); //lamdha expression for odd members

    cout<<"Number of oddnumber occurences::"<<count1<<endl;

}

int main(){

    find_demo();
    count_demo();
    count_if_demo();

    return 0;
}