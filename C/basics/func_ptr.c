#include <stdio.h>

void myfunc(){
    printf("Hello world\n");
}

int add(int a, int b){
    return a+b;
}

//FUnction pointer syntax

// return type (*ptrname)(arguments) = &func_name


int main(){

    void(*func_ptr)() = &myfunc;
    func_ptr();

    int(*add_func_ptr)(int,int) = &add;

    printf("a + b = %i\n",add(5, 10));


    return 0;
}