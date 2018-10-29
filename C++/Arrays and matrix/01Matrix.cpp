/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

Link:
https://leetcode.com/problems/01-matrix/
*/

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
	{
	    int rows = matrix.size();
	    if (rows == 0)
	        return matrix;
	    int cols = matrix[0].size();
	    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
	    queue<pair<int, int> > q;
	    for (int i = 0; i < rows; i++)
	        for (int j = 0; j < cols; j++)
	            if (matrix[i][j] == 0) {
	                dist[i][j] = 0;
	                q.push({ i, j }); //Put all 0s in the queue.
	            }

	    vector<vector<int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	    while (!q.empty()) {
	        pair<int, int> curr = q.front();
	        q.pop();
	        for (auto d : dir) {
	            int new_r = curr.first + d[0], new_c = curr.second + d[1];
	            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
	                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
	                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
	                    q.push({ new_r, new_c });
	                }
	            }
	        }
	    }
	    return dist;
	}

	// Using DP
	vector<vector<int> > updateMatrixDP(vector<vector<int> >& matrix)
	{
	    int rows = matrix.size();
	    if (rows == 0)
	        return matrix;
	    int cols = matrix[0].size();
	    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

	    //First pass: check for left and top
	    for (int i = 0; i < rows; i++) {
	        for (int j = 0; j < cols; j++) {
	            if (matrix[i][j] == 0)
	                dist[i][j] = 0;
	            else {
	                if (i > 0)
	                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
	                if (j > 0)
	                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
	            }
	        }
	    }

	    //Second pass: check for bottom and right
	    for (int i = rows - 1; i >= 0; i--) {
	        for (int j = cols - 1; j >= 0; j--) {
	            if (i < rows - 1)
	                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
	            if (j < cols - 1)
	                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
	        }
	    }

	    return dist;
	}
};

