/**
 * @file Integer.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 * In this class we demonstrate raw pointer as data member.
 * What kind issues it creates in the copy constructor:concepts of deep copy vs shallow copy etc
 */

 #include <iostream>
 #include <string>


 using namespace std;

 class Integer{
    private:
        int* data;
    public:
        Integer(int value=0);
        Integer(const Integer &integer);
        ~Integer(){
            cout<<"-------- destructor is called -------"<<endl;
            delete data;
        }

        int getData(){
            return *this->data;
        }

        void setData(int data){
            *this->data = data;
        }

        void display(){
            cout<<"Int Value is: "<<*this->data<<endl;
        }

        void display(Integer);

 };

Integer::Integer(int value){
    cout<<"---one arg constructor----"<<endl;
    data = new int(value);
}

Integer::Integer(const Integer &source){
    cout<<"---copy constrcutor----"<<endl;
    this->data = new int;
    *this->data = *(source.data); //shallow copy. Just copying pointer address.
}

void Integer::display(Integer obj){
    cout<<"Integer value is: "<<obj.getData()<<endl;
}

int main(){

    Integer p{5};

    p.display(p);

    
    p.display();
    

    return 0;
}