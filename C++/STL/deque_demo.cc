/**
 * Deque demo: Deque is very similar like vector. Will solve palindrome problem in this example:
 */

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

void print(deque<int> d){
    for ( auto item: d){
        cout<<item<<" ";
    }
    cout<<endl;
}

void demo1(){
    deque<int> test = { 1, 2, 3, 4, 5};
    print(test);

    deque<int> test1(5, 1);
    print(test1);

    cout<<test.front()<<endl;
    cout<<test.back()<<endl;
    test.pop_front();
    test.push_front(10);
    print(test);
}

bool is_palindrome(string s){
    deque<char> str;
    for (auto c : s){
        str.push_back(c);
    }

    int length = str.size();
    int count = 0;
    while (count < length/2){
        if(str.front() == str.back()){
            str.pop_front();
            str.pop_back();
        }else{
            return false;
        }
        count++;

    }

    return true;
}

int main(){

    demo1();
    cout<<is_palindrome("madam")<<endl;
    cout<<is_palindrome("true")<<endl;
    
    return 0;
}