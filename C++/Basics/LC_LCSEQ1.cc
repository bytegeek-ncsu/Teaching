/**
 * @file LC_LCSEQ1.cc
 * @author Shakthi (shak@bytegeek.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-20
 * 
 * @copyright Copyright (c) 2026
 * 
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3

 * This is my first brute force attempt.
 */
#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Function LCSequence from give array
 * Input: Int array
 * output: Int
 * Pseudo code:
 * int ans = 1;
 * for (int i=0; i< array.length; i++){
 *  seq = 0
 *  while (contains(num, array)){
 *      num++;
 *      seq++;
 *  }
 *  if (seq > ans)
 *      ans = seq;
 * 
 * }
 * 
 * bool contains(num, array){
 *    for (int i : array)
 *      if (i == num)
 *          return true
 *    return false;
 * }
 * 
 */
bool contains(int num, vector<int>& nums){
    for (int i : nums){
        if (num == i)
            return true;
    }
    return false;
}

int longestConsSequence(vector<int>& nums){
    int ans = 1;
    
    for (int num : nums){
        int seq = 0;
        while (contains(num, nums)){
            num++;
            seq++;
        }

        if (seq > ans)
            ans = seq;
    }

    return ans;
    
}


   

int main(){
    //vector<int> seq = {100,4,200,1,3,2};
    vector<int> seq = {0,3,7,2,5,8,4,6,0,1};
    cout<<longestConsSequence(seq)<<endl;
    return 0;
}

