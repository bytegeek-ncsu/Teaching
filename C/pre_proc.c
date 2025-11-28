#include<stdio.h>

//This code some cool things of preprocessor the compiler feature

#define TEST


// The idea of this code is if you define TEST then this function will get compiled. or this micro will be part of compile

//Here is the second feature of preprocessor. You can add macro in our code

#define blah(x, y) printf("%i, %i\n", x,y )

//The above code is just a macro we are defining saying if you have code like blah(x,y) then replace
// that with printf("%i, %i\n", x,y )

#ifdef TEST
void test(){

}
#endif

int main(){

    test();
    blah(5,10);
    return 0;
}