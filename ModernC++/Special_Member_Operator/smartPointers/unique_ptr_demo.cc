/**
 * THis code demonstrates smart pointer and also explains the concept of operator overloading
 * it also explain type conversion.
 */

//#pragma once

#include <iostream>
#include <memory>

class Test {
	int *m_pInt;
public:
	//Default constructor
	Test();
	//Parameterized constructor
	Test(int value);
	//Copy constructor
	Test(const Test &obj);
	//Move constructor
	Test(Test &&obj);
	int GetValue()const;
	void SetValue(int value);
	~Test();
	Test & operator ++();
	Test operator ++(int);
	bool operator ==(const Test &a)const;

	//Copy assignment
	Test & operator =(const Test &a);
	//Move assignment
	Test & operator =(Test &&a);
	Test operator +(const Test & a)const;

	void operator ()();

    //user defined object to primitive type conversion
    // operator <type>()  1. no argument and no return type in this conversion
    operator int();
};

//Global functions
Test operator +(int x, const Test &y);
std::ostream & operator <<(std::ostream & out, const Test &a);
std::istream & operator >> (std::istream &input, Test &a);

Test::Test() {
	std::cout << "Test()" << std::endl;
	m_pInt = new int(0);
}

Test::Test(int value) {
	std::cout << "Test(int)" << std::endl;
	m_pInt = new int(value);
}

Test::Test(const Test & obj) {
	std::cout << "Test(const Test&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Test::Test(Test && obj) {
	std::cout << "Test(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Test::GetValue() const {
	return *m_pInt;
}

void Test::SetValue(int value) {
	*m_pInt = value;
}

Test::~Test() {
	std::cout << "~Test()" << std::endl;
	delete m_pInt;
}

Test & Test::operator++() {
	++(*m_pInt);
	return *this;
	// TODO: insert return statement here
}

Test  Test::operator++(int) {
	Test temp(*this);
	++(*m_pInt);
	return temp;
}

bool Test::operator==(const Test & a) const {
	return *m_pInt == *a.m_pInt;
}

Test & Test::operator=(const Test & a) {
	if (this != &a) {
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

Test & Test::operator=(Test && a) {
	if (this != &a) {
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}



Test Test::operator+(const Test & a) const {
	Test temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

void Test::operator()() {
	std::cout << *m_pInt << std::endl; 
}

Test::operator int()
{
    return *m_pInt;
}

Test operator +(int x, const Test &y) {
	Test temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}
std::ostream & operator <<(std::ostream & out, const Test &a) {
	out << a.GetValue();
	return out;
}
std::istream & operator >> (std::istream &input, Test &a) {
	int x;
	input >> x;
	a.SetValue(x);
	return input;
}

void move_unique_ptr(std::unique_ptr<Test> ptr) {
    std::cout<<ptr->GetValue()<<std::endl;   

}

void CreateInteger() {
    std::unique_ptr<Test> test_ptr(new Test(5));
    //auto dummy_ptr(test_ptr); // This code is not allowed since copy ctr is deleted in unque pointer
    //Now let me pass test_ptr as a value to function move_unique_ptr.
    //move_unique_ptr(test_ptr); can't . Same issue like above

    //Here is the classic case of how to use std::move
    move_unique_ptr(std::move(test_ptr));
}

/**
 * Since unique poiter cannot be copied you cannot pass them as a value.
 * Instead copy we can move the unique pointer. Watch in the createInteger fucntion
 */
	


int main() {
	CreateInteger(); //When invoke this both constructor and destructor of test class gets called.
    Test t {5}; //In this case it is uses parameterized constr
    Test t1 = 8; //In this ctr used for type conversion from primitive to UDO. How when
    // we declare and initialize constant 8 compiler look for corresponding constr exists are not. If so it will invoke 
    //implicitly and initialize t1.
    //This concepts applies when you call function by value. 

    //suppose we say 
    t = 8;
    //In this case it it will first contruct using parameteriszed constructor and then use move assignment operator.
    //we can mark of constructor as explicit to disallow the type conversion.

    int p = t; //This will invoke int() operator function.

    

    return 0;
}