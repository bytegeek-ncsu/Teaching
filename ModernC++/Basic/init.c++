#include <iostream>
#include <vector>
#include <string>

/*
*In this code we will explore how we can declare and initialize 
* variables and objects in Modern C++
*/

//typedef vector<int> IntVec;
//In modern C++ instead of typedef we should use the "using" Keyword
using IntVec = vector<int>;

using namespace std;

void print (vector<int>& vec){
    for (auto v: vec)
        cout<<v<<endl;
}




int main(){

    int x{7};
    string s{"Hello this is new C++"};
    cout<<"X value is "<<x<<endl;
    cout<<"String value is "<<s<<endl;

    vector<int> vec{4,7,8,9,10};
    print(vec);
    
    string hello{'H', 'e', 'l', 'l', 'o'}; 
    //Here we are using escape sequences.
    cout << endl << "hello = \"" << hello << "\"" << endl; 

    vector<int> old_one(4);         // std::vector variable with elements 0, 0, 0, 0
	vector<int> old_two(4, 2);      // std::vector variable with elements 2, 2, 2, 2
	vector<int> uni_one{4};         // std::vector variable with elements 4
	vector<int> uni_two{4, 2};      // std::vector variable with elements 4, 2
	
	cout << "old_one = ";
	print(old_one);
	
	cout << endl << "old_two = ";
	print(old_two);
	
	cout << endl << "uni_one = ";
	print(uni_one);
	
	cout << endl << "uni_two = ";
	print(uni_two);
    
    //error: narrowing conversion of '7.7000000000000002e+0' from 'double' to 'int' [-Wnarrowing
    //int y{7.7}; 

    return 0;
}