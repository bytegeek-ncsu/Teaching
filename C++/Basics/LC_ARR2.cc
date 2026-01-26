/**
 * @file LC_ARR2.cc
 * @author Shak (shak@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-25
 * 
 * @copyright Copyright (c) 2026
 * Find the max SubArray
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int> &arr){
    int max = 0;
    int streak = 0;
    for (int num : arr){
        streak += num;
        if (streak < 0)
            streak = 0;
        if (streak > max)
            max = streak;

    }

    return max;
}

int main(){
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<maxSubArray(numbers)<<endl;
    vector<int> numbers1 = {5, 4, -1, 7, 8};
    cout<<maxSubArray(numbers1)<<endl;
    return 0;
}