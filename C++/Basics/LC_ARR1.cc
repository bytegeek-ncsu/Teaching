/**
 * @file LC_ARR1.cc
 * @author Shak(shak@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-25
 * 
 * @copyright Copyright (c) 2026
 * 
 * This code finds the maximum number of consequtive one from the give array
 * 
 */
#include<iostream>
#include<vector>


using namespace std;

int maxConsOnes(vector<int> &numbers){
    int count = 0;
    int maxCount = 1;
    for (auto num : numbers){
        if (num == 1)
            ++count;
        else{    
            
            if (count > maxCount)
                maxCount = count;
            count = 0;
        }
    }

    return maxCount;

    
}

int main(){
    vector<int> example = {1, 0, 1, 1, 0, 1};
    cout<<maxConsOnes(example)<<endl;
    return 0;
}

