/**
 * @file move_example.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 * In this class we are going demostrate move constructor and how it helps in avoiding object copying
 * Explosion
 */

 #include <iostream>
 #include <string>
 #include <vector>


 using namespace std;

 class Integer{
    private:
        int* data;
    public:
        Integer(int value=0);
        Integer(const Integer &integer);
        Integer(Integer &&source); //THis is is move construcotor we are using to move the raw pointer. Look r-value reference
        ~Integer(){
            if(data)
                cout<<"-------- destructor is called and cleaning data -------"<<endl;
            else //it means data is already nullified
                cout<<"-------- destructor is called and cleaning null ptr -------"<<endl;

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

Integer::Integer(Integer &&source){
    cout<<"---Move constrcutor----"<<endl;
    this->data = source.data;
    source.data = nullptr; //We are simply steeling source raw pointer.
}

void Integer::display(Integer obj){
    cout<<"Integer value is: "<<obj.getData()<<endl;
}

int main(){
    vector<Integer> intVector;
    intVector.push_back(Integer(10));
    intVector.push_back(Integer(20));
    intVector.push_back(Integer(30));
    intVector.push_back(Integer(40));
    intVector.push_back(Integer(50));
    intVector.push_back(Integer(60));
    intVector.push_back(Integer(70));
    
}