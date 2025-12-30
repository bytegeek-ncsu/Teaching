/**
 * In this code will demostrate default and delete keyword impact
 */

 #include <iostream>

class Test{
    int value;
public:
    Test() = default;

    Test(int a_value):value(a_value){}

    Test (const Test &)  = delete;

    void set(int value){
        this->value = value;
    }

    void set(float) = delete;



};

int main(){
    Test t;
    t.set(5);
    t.set(6.3); // Both of these errors. We can't use float as a type for set function

    Test t3{t}; // Here we deleted copy constructor. So we cannot use copy operation.


}