/*
 
674. Longest Continuous Increasing Subsequence
 
 https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 
 Given an unsorted array of integers, find the length of longest continuous increasing subsequence.
 
 Example 1:
 Input: [1,3,5,4,7]
 Output: 3
 Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 Example 2:
 Input: [2,2,2,2,2]
 Output: 1
 Explanation: The longest continuous increasing subsequence is [2], its length is 1.
 Note: Length of the array will not exceed 10,000.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        if (nums.size()==1) { return 1; }
        int max_len=1, curr_len=1;
        for (int i=0; i < nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                max_len = max(max_len, ++curr_len);
            } else {
                curr_len=1;
            }
        }
        return max_len;
    }
};

int main(int argc, const char * argv[]) {
  
    vector<int> nums { 1,3,5,4,7 };
    
    Solution solution;
    cout << solution.findLengthOfLCIS(nums) << endl;
    
    return 0;
}



