#include<iostream>

using namespace std;

void func(int x, int y){
    cout<<x<<" + "<<y<<" = "<<x+y<<endl;
}

//Here we are creating alias for our function func using "using" directive

using pfunc = void(*)(int,int);

//In this function we are using pfunc function pointer as an argument in our new function

void some_func(int x, int y, pfunc abc){
    (*abc)(x,y); // The * before abc is optional. But it is good practice to use 

}

//This function is returning our function pointer
pfunc other_func(){
    return &func; //Here & is optional. But it is good practice to use it.
}

int main(){

    auto func_ptr = other_func();

    some_func(6,15, func_ptr);


    return 0;
}