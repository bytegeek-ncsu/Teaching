/**
 * @file LC_ARR3.cc
 * @author Shak (shak@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-25
 * 
 * @copyright Copyright (c) 2026
 * Product of Array except by itself
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> prodExceptSelf(vector<int> &nums){
    int length = nums.size();
    vector<int> left(length, 1);
    vector<int> right(length, 1);
    vector<int> result(length, 1);
    
   
    for (int i=1; i<length; i++)
        left[i] = left[i-1]*nums[i-1];
    for (int i=length-2; i>=0; i--)
        right[i] = right[i+1]*nums[i+1];
    for (int i=0; i<length; i++)
        result[i] = left[i]*right[i];
    return result;
}

int main(){
    vector<int> num1 = {1, 2, 3, 4};
    vector<int> output = prodExceptSelf(num1);
    for (auto num : output)
        cout<<num<<" ";
    cout<<endl;

    return 0;
}

