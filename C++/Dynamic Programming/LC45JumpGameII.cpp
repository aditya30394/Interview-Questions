/*
LC45
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/


class Solution {
public:
    // O(n^2)
    int jump1(vector<int>& nums) 
    {
        vector<int>dp(nums.size(),INT_MAX);
        dp[0]=0;
        int n = nums.size();
        int i=1,j=0;
        for(i=1;i<n;++i)
        {
            j=0;
            while(j<i)
            {
                if(j+nums[j]>=i)
                    dp[i] = min(dp[i], dp[j]+1);
                ++j;
            }
        }
        return dp[n-1];
    }
};

// BFS
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
            return 0;
        
        int levels =0;
        int nextLevelEnd = 0;
        int currentLevelEnd = 0;
        
        for(int i=0;i<n;++i)
        {
            if(i>currentLevelEnd)
            {
                ++levels;
                currentLevelEnd = nextLevelEnd;
            }
            nextLevelEnd = max(nextLevelEnd, i+nums[i]);
            
        }
        return levels;
    }
};