/*
Print all paths from top left to bottom right in a matrix with four moves allowed
The problem is to print all the possible paths from top left to bottom right of an mXn matrix with the constraints 
that from each cell you can either move up, right, left or down.

Examples:

Input :  
1 2 3 
4 5 6 
Output :  
1 2 3 6 
1 2 5 6  
1 4 5 6  
4 5 2 3 6 

Input :
1 2 3
4 5 6
7 8 9
Output :
1 2 3 6 9 
1 2 3 6 5 8 9 
1 2 3 6 5 4 7 8 9 
1 2 5 6 9 
1 2 5 8 9 
1 2 5 4 7 8 9 
1 4 5 6 9 
1 4 5 8 9 
1 4 5 2 3 6 9 
1 4 7 8 9
1 4 7 8 5 6 9                                                                                                                                                                      
1 4 7 8 5 2 3 6 9 
Recommended: Please try your approach on {IDE} first, before moving on to the solution.


This problem is mainly an extension of Count all paths from top left to bottom right in a matrix with two moves allowed

The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths 
by going right then print all paths by going up then print all paths by going left. Do this recursively for each cell encountered. 
There we will use Hash matrix for it will not repeat the same path which already traversed.


Link:https://www.geeksforgeeks.org/print-all-paths-from-top-left-to-bottom-right-in-a-matrix-with-four-moves-allowed/
*/


// Print All path from top left to bottom right 
#include <iostream> 
#include <vector> 
using namespace std; 
  
void printAllPath(vector<vector<int>>& vec, 
                  vector<vector<int>>& hash,
                  int i, int j,
                  vector<int> path={})
{
    if(i<0 || j<0 || i>=vec.size() || j>=vec[0].size() || hash[i][j]==1)
    {
        return;
    }
    
    if(i==vec.size()-1 && j==vec[0].size()-1)
    {
        path.push_back(vec[i][j]);
        for(int&p:path)
        {
            cout<<p<<" ";
        }
        cout<<endl;
        return;
    }
    
    hash[i][j]=1;
    path.push_back(vec[i][j]);
    printAllPath(vec, hash, i, j+1, path);
    printAllPath(vec, hash, i+1, j, path);
    printAllPath(vec, hash, i-1, j, path);
    printAllPath(vec, hash, i, j-1, path);
    hash[i][j]=0;
}                  
  
// Driver code 
int main() 
{ 
    // Given matrix 
    vector<vector<int> > vec = { { 1, 2, 3 }, 
                                 { 4, 5, 6 },
                                 { 7,8,9 }}; 
  
    // mxn(2x3) 2d hash matrix 
    vector<vector<int> > hash(3, vector<int>(3, 0)); 
  
    // print All Path of matrix 
    printAllPath(vec, hash, 0, 0); 
  
    return 0; 
}


