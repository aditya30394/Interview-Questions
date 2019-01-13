/*
120. Triangle
Medium

883

91

Favorite

Share
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

// TOP-DOWN 1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        
        if(n==1)
            return triangle[0][0];
        vector<int>dp(n, INT_MAX);
        dp[0]=triangle[0][0];
        
        for(int i=1;i<n;++i)
        {
            int m = triangle[i].size();
            vector<int> prev = dp;
            for(int j=0;j<m;++j)
            {
                int a1= (j-1)>=0?prev[j-1]:INT_MAX;
                int a2 = j<i?prev[j]:INT_MAX;
                dp[j]=triangle[i][j]+ min(a1,a2);
            }
            
        }
        return *min_element(dp.begin(), dp.end());
    }
};

// without extra copy vector
// go backward
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        
        if(n==1)
            return triangle[0][0];
        vector<int>dp(n, INT_MAX);
        dp[0]=triangle[0][0];
        
        for(int i=1;i<n;++i)
        {
            for(int j=i;j>=0;--j)
            {
                int a1= (j-1)>=0?dp[j-1]:INT_MAX;
                int a2 = j<i?dp[j]:INT_MAX;
                dp[j]=triangle[i][j]+ min(a1,a2);
            }
            
        }
        return *min_element(dp.begin(), dp.end());
    }
};

// Cleaner top-down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        
        if(n==1)
            return triangle[0][0];
        vector<int>dp(n, INT_MAX);
        dp[0]=triangle[0][0];
        
        for(int i=1;i<n;++i)
        {
            for(int j=i;j>=0;--j)
            {
                if(j==0)
                {
                    dp[j]=dp[j]+triangle[i][j];
                }
                else if(j==i)
                {
                    dp[j]=dp[j-1]+triangle[i][j];
                }
                else
                {
                    dp[j] = triangle[i][j]+min(dp[j],dp[j-1]);
                }
            }
            
        }
        return *min_element(dp.begin(), dp.end());
    }
};


// Bottom up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        
        if(n==1)
            return triangle[0][0];
        vector<int>dp(triangle[n-1]);
        
        for(int i=n-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
            
        }
        return dp[0];
    }
};
