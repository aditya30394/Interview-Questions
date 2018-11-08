/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=1;i<n;++i)
            grid[0][i]+=grid[0][i-1];
        
        for(int i=1;i<m;++i)
            grid[i][0]+=grid[i-1][0];
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                grid[i][j]=grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(m,grid[0][0]);
        
        for(int i=1;i<m;++i)
        {
            curr[i] = curr[i-1]+grid[i][0];
        }
        
        for(int j=1;j<n;++j)
        {
            curr[0] = curr[0]+grid[0][j];
            for(int i=1;i<m;++i)
            {
                curr[i]= min(curr[i-1], curr[i])+grid[i][j];
            }
        }
        
        return curr[m-1];
    }
};

public int minPathSum(int[][] grid) {
       int rows = grid.length;
        int cols = grid[0].length;
        int[] dp = new int[cols];
        for (int i = 0; i < rows; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < cols; j++) {
                dp[j] = (i == 0 ? dp[j - 1] : Math.min(dp[j], dp[j - 1])) + grid[i][j];
            }
        }
        return dp[cols - 1];
    }

    