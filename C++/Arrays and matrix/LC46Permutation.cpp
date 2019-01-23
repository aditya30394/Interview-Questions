/*
46. Permutations
Medium

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
    vector<vector<int>> perms;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return perms;
    }
    
    void backtrack(vector<int>&nums, int start)
    {
        if(start==nums.size())
        {
            perms.push_back(nums);
            return;
        }
        
        for(int i=start; i< nums.size();++i)
        {
            swap(nums[start], nums[i]);
            backtrack(nums, start+1);
            swap(nums[start], nums[i]);
        }
        
        
    }
};