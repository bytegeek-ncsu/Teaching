#include<iostream>
#include<string>

using namespace std;

int main(){

    string str{"Hello World"s};

    auto first = begin(str);

    //If we use this last place then end of the string is 0 or null charactero
    //auto last = end(str);
    //so we have to use end(str)-1

    auto last = end(str)-1;

    //Here first and last or iterator pointer

    cout<<*first<<endl;
    cout<<*last<<endl;

    int number_chars = last - first;
    cout<<"The number of char in the string is : "<<number_chars<<endl;

    auto second = next(begin(str)); //this will return the second element
    auto last_new  = prev(end(str));

    cout<<distance(begin(str),end(str))<<endl;


    return 0;
}