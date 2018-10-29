// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
#include<vector>

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // Basically we have to calculate the number of "new" maximums that we get
    // Why? Because if a new student has height which is less than the height of tallest
    // person in any of the previously created rows, he/she will join that existing row.
    // But if the new student is taller than all the row-wise tallest person, he will create
    // a separate new row. Thus we basically need to calculate the number of times we get a
    // "new tallest" student
    
    // if there are no students then there can be no rows
    if(A.size()==0)
    {
        return 0;
    }
    // we will have at least 1 row if we have >=1 students
    int noOfRows = 1;
    int currMax = A[0];
    for(size_t i =1; i<A.size(); ++i)
    {
        if(A[i]>currMax)
        {
            // we need a new row then
            ++noOfRows;
            // Max also has changed now - for the next comparision
            currMax=A[i];
        }
    }
    return noOfRows;
}