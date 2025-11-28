#include<iostream>
#include<string>

using namespace std;

/*
    String search basic function is find. it returns the index of the search
    string we are passing

    If there is no match it returns type string::npos.

    if we want to search from the reverse side of the string rfind.
*/

int main(){

    string str {"Hello world"};
	cout << "Initial contents of str: " << str << endl;
	
	size_t pos = str.find('o');
	
	if (pos != string::npos) {
		str[pos] = 'p';
	}
	else {
		cout << "Could not find the search string\n";
	}
	
	cout << "Final contents of str:   " << str << endl;
	
	size_t pos1 = str.rfind('o');
	
	if (pos1 != string::npos) {
		str[pos1] = 'p';
	}
	else {
		cout << "Could not find the search string\n";
	}
	
	cout << "Final contents of str:   " << str << endl;

    return 0;
}