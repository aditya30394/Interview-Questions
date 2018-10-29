// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include<vector>
using namespace std;

// This is a modified binary search algorithm, which returns the "value" which
// is closes to our target. 

int BinarySearch(int target, vector<int>& a) 
{
    
    // if target is smaller than the smallest element, then just return the smallest
    if(target < a[0]) 
    {
        return a[0];
    }
    
    // similarly, if the target is greater than the largest element, then just return the largest    
    if(target > a[a.size()-1]) 
    {
        return a[a.size()-1];
    }

    int l = 0;
    int h = a.size() - 1;

    while (l <= h) 
    {
        int mid = (h + l) / 2;
        if (target < a[mid]) 
        {
            h = mid - 1;
        } 
        else if (target > a[mid]) 
        {
            l = mid + 1;
        } 
        else 
        {
            // if we get a match then just return the value.
            return a[mid];
        }
    }
    // If we didn't find the exact match then we need to see which one is the closest value to our target.   
    return (a[l] - target) < (target - a[h]) ? a[l] : a[h];
}
    
vector<int> solution(vector<int> &stores, vector<int> &houses) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> ans;
    // sort the location vector
    // Why? Because we can use Binary search to find the closest store location.
    // Each run of Binary search will take O(log S), where S is the size of stores array.
    // Other alternative is using a slower linear search algorithm which would run in O(n)
    sort(stores.begin(), stores.end());
    
    for(int& house: houses)
    {
        // use the modified BinarySearch to find the closest store near our target house
        ans.push_back(BinarySearch(house,stores));
    }
    return ans;
}