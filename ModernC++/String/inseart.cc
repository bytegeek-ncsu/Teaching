#include<iostream>
#include<string>

using namespace std;


int main(){

    /*
    * Append function examples
    */
    string hello {"Hello"};
	
	hello.append(" world"s);
	cout << "hello = " << hello << endl;
	
	string hello2 {"Hello"s};
	
	hello2.append("wow!!!!"s, 3, 2);
	cout << "hello2 = " << hello2 << endl;

    /*
    * Insert function examples
    */

    string str{ "for" };
	cout << "str = " << str << endl;
	
	str.insert(2, "lde"s);
	cout << "str = " << str << endl;
	
	string str2{ "care" };
	cout << "str2 = " << str2 << endl;

	string str3{ "omp" };
	str2.insert(1, str3);
	cout << "str2 = " << str2 << endl;

    /*
    * Inseart using iterators
    */

    string str{"word"};
	cout << "str = " << str << endl;

	auto last = end(str) - 1;                  // Get iterator to last character

	// Insert 'l' before last character
	str.insert(last, 'l');
	cout << "str = " << str << endl;

	string str2{"ski"};
	cout << "str2 = " << str2 << endl;
	auto last2 = end(str2);                  // Get iterator to last character plus one

	// Insert 'l' twice, after last character
	str2.insert(last2, 2, 'l');
	cout << "str2 = " << str2 << endl;

    return 0;
}