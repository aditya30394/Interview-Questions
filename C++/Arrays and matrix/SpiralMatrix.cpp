/*
Spiral Matrix problem

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Link: https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/828/

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        vector<int> output;
        
        if(r==0)
            return output;
        
        int c = matrix[0].size();
        
        int k = 0; // current row
        int l = 0; // current col
        int i = 0; // iterator
        
        while(k<r && l<c)
        {
            for(i=l; i<c; ++i)
            {
                output.push_back(matrix[k][i]);
            }
            ++k;
            
            for(i=k;i<r;++i)
            {
                output.push_back(matrix[i][c-1]);
            }
            --c;
            
            if(k<r)
            {
                for(i=c-1;i>=l;--i)
                {
                    output.push_back(matrix[r-1][i]);
                }
                
            }
            --r;
            
            if(l<c)
            {
                for(i=r-1;i>=k;--i)
                {
                    output.push_back(matrix[i][l]);
                }
                
            }
            ++l;
        }
        return output;
    }
};

