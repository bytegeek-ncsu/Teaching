/**
 * @file fib_version1.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Fib sequence using recursion
 */

#include <iostream>

using namespace std;

static int counter = 0;
int fib(int n){
    counter++;
    if (n == 0 || n== 1)
        return n;
    return fib(n-1) + fib(n-2);

}

int main(){

    int n = 11;
   
    cout<<" Fib number of : "<<n<< ":: "<<fib(n)<<endl;

    cout<<"Number of fib calls: "<<counter<<endl;

    return 0;
}