/*
73. Set Matrix Zeroes
Medium

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return;
        int n = matrix[0].size();
        
        bool firstRowZero=false, firstColZero=false;
       
        for(int i=0;i<m;++i)
        {
            for(int j =0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        firstRowZero=true;
                    }
                    if(j==0)
                    {
                        firstColZero=true;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                
            }
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j =1;j<n;++j)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
                
            }
        }
            
        if(firstRowZero)
        {
            nullifyRow(matrix,0);
        }
        
        if(firstColZero)
        {
            nullifyCol(matrix,0);
        }
    }
    
    void nullifyRow(vector<vector<int>>& matrix, int row)
    {
        for(int i=0; i<matrix[0].size();++i)
        {
            matrix[row][i]=0;
        }
    }
    
    void nullifyCol(vector<vector<int>>& matrix, int col)
    {
        for(int i=0; i<matrix.size();++i)
        {
            matrix[i][col]=0;
        }
    }
};