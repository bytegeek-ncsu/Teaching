#include <iostream>

using namespace std;

int func(int y) {                // y will be a copy of the caller's variable x
	cout << "Address of y is " << &y << endl;
	return y;                    // Copy y into the function's return value
}

//Here we are trying to pass by reference regular pointer
int func1(int *y) {                // y will be a copy of the caller's variable x
	cout << "Address of y is " << y << endl;
    *y = 1;
	return *y;                    // Copy y into the function's return value
}

//Here we are trying to pass by reference using C++ reference object
int func2(int &y) {                // y will be a copy of the caller's variable x
	cout << "Address of y is " << &y << endl;
    y = 1;
	return y;                    // Copy y into the function's return value
}


int main() {
	int x = 2;
	cout << "Address of x is " << &x << endl;
	int z = func2(x);              // z will be a copy of func's return value
	cout << "Address of z is " << &z << endl;
    cout << "After calling func(), x = " << x << endl;
	cout << "After calling func(), z = " << z << endl;
}