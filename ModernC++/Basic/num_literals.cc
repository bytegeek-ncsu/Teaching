#include<iostream>
#include<cstdint>
#include<basetsd.h>

using namespace std;

int main(){

    //Formatted numerical constants

    int one_mil = 1'000'000;
    float pi = 3.143'333'333;

    cout<<"one million is:"<<one_mil<<endl;
    cout<<"The value of the pi is:"<<pi<<endl;

    cout << "char: " << sizeof(char) << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	
	cout << "int8_t: " << sizeof(int8_t) << endl;
	cout << "int16_t: " << sizeof(int16_t) << endl;
	cout << "int32_t: " << sizeof(int32_t) << endl;
	cout << "int64_t: " << sizeof(int64_t) << endl;
	cout << endl;
	
	cout << "uint8_t: " << sizeof(uint8_t) << endl;
	cout << "uint16_t: " << sizeof(uint16_t) << endl;
	cout << "uint32_t: " << sizeof(uint32_t) << endl;
	cout << "uint64_t: " << sizeof(uint64_t) << endl;

    //Here some of the bases lets looks at octals and binary

    int Octal = 042;

    cout<<Octal<<endl;

    int binary = 0b01000110;

    cout<<binary<<endl;



    return 0;
}