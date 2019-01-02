/*
Print all possible paths from top left to bottom right of a mXn matrix
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
Examples :

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths by going right. Do this recursively for each cell encountered.

*/

// Working But ineffective solution - because it uses a lot of extra vector copying

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

void printAllPaths(vector<vector<int>>& mat, int m, int n, int i, int j, vector<int> path);

int main()
{
    vector<vector<int>> mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector<int>path;
    printAllPaths(mat, 2, 2, 0, 0, path);
    /*
	correct output is :
	1 4 7 8 9 
	1 4 5 8 9 
	1 4 5 6 9 
	1 2 5 8 9 
	1 2 5 6 9 
	1 2 3 6 9
	But if we pass the path vector by reference, then it's a problem
	1 4 7 8 9 
	1 4 7 8 9 5 8 9 
	1 4 7 8 9 5 8 9 6 9 
	1 4 7 8 9 5 8 9 6 9 2 5 8 9 
	1 4 7 8 9 5 8 9 6 9 2 5 8 9 6 9 
	1 4 7 8 9 5 8 9 6 9 2 5 8 9 6 9 3 6 9  
    */ 
    return 0; 
}

void printAllPaths(vector<vector<int>>& a, int m, int n, int i, int j, vector<int> path)
{
    if(i==m && j==n)
    {
        path.push_back(a[i][j]);
        for(int& p:path)
        {
            cout<<p<<" ";
        }
        cout<<endl;
        return;
    }
    if(i>m || j>n)
        return;
    
    path.push_back(a[i][j]);
    printAllPaths(a,m,n,i+1,j,path);
    printAllPaths(a,m,n,i,j+1,path);
    
}


// A more efficient implementation is:

// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

void printAllPaths(vector<vector<int>>& mat, int m, int n, int i, int j, vector<int>& path, int len);

int main()
{
    vector<vector<int>> mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int m = mat.size();
    int n = mat[0].size();
    vector<int>path(m+n, -1);
    printAllPaths(mat, m-1, n-1, 0, 0, path, 0); 
    return 0; 
}

void printAllPaths(vector<vector<int>>& a, int m, int n, int i, int j, vector<int>& path, int len)
{
    if(i==m && j==n)
    {
        path[len]=a[i][j];
        for(int p=0;p<=len;++p)
        {
            cout<<path[p]<<" ";
        }    
        cout<<endl;
        return;
    }
    if(i>m || j>n)
        return;
    
    path[len]=a[i][j];
    printAllPaths(a, m, n, i+1, j, path, len+1);
    printAllPaths(a, m, n, i, j+1, path, len+1);
    
}

