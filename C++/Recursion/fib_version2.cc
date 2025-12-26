/**
 * @file fib_version2.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Fib sequence using memoization
 */

#include <iostream>
#include <vector>

using namespace std;

static int counter = 0;
vector<int> fibHistory(100, -1);
int fib(int n){
    counter++;
    if (fibHistory[n] != -1) // it means we have a fib value for the given nubmer
        return fibHistory[n];
    if (n == 0 || n== 1)
        return n;
    fibHistory[n] = fib(n-1) + fib(n-2);
    return fibHistory[n];

}

int main(){

    int n = 21;
   
    cout<<" Fib number of : "<<n<< ":: "<<fib(n)<<endl;

    cout<<"Number of fib calls: "<<counter<<endl;

    return 0;
}