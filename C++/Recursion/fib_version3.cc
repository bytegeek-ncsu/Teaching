/**
 * @file fib_version3.cc
 * @author Shak (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-26
 * 
 * @copyright Copyright (c) 2025
 * 
 * Fib sequence using iterative technique
 */

#include <iostream>
#include <vector>

using namespace std;

static int counter = 0;

int fib(int n){
    vector<int> fibValue;
    fibValue.push_back(0); //[0] = 0
    fibValue.push_back(1); //[1] = 1

    for (int i=2; i <= n; i++){
        counter++;
        fibValue[i] = fibValue[i-1]+fibValue[i-2];
    }

    return fibValue[n];

}

int main(){

    int n = 11;
   
    cout<<" Fib number of : "<<n<< ":: "<<fib(n)<<endl;

    cout<<"Number of fib calls: "<<counter<<endl;

    return 0;
}