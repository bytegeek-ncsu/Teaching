#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> vec{2,5,7,9,10};
    char c;
    int ws_count{0};

    const char* sent{"What the hell are we doing\t here?\n"};
    auto first = begin(vec);

    if(first != end(vec)) //This condition checks the vector is not empty
        cout<<*first<<endl;

    //C++ 17 implementaiton

    if(first=begin(vec); first != end(vec))
        cout<<*first<<endl;

    for (int i=0; sent[i]; ++i){

        switch(const char c=sent[i]; c){

            case ' ':
            case '\t':
            case '\n':
                ++ws_count;
                break;
            default:
                break;

        }
    }

    cout<<"the number of white space in the sentence is :: "<<ws_count<<endl;

    ws_count = 0;
    //C++ has special feature in switch is fallthrough cases. To remai
    //This is a standard feauture in C++ we can use attributes like
    //[[fallthrough]]

    for (int i=0; sent[i]; ++i){

        switch(const char c=sent[i]; c){

            case ' ':
                [[fallthrough]];
            case '\t':
                [[fallthrough]];
            case '\n':
                //[[fallthrough]];
                ++ws_count;
                break;
            default:
                break;

        }
    }

    cout<<"the number of white space in the sentence is :: "<<ws_count<<endl;

    return 0;
}