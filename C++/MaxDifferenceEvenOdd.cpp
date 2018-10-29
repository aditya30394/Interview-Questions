/*
Problem is a slight modification of the usual max difference problem

Link: https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int firstOdd(vector<int>& a)
{
    for(int i=0;i<a.size();++i)
    {
        if(a[i]%2!=0)
        {
            return i;
        }
    }
    return -1;
}

int maxDifferenceOddEven(vector<int>& a) 
{
    int firstodd = firstOdd(a);
    if(firstodd==-1)
    {
        return -1;
    }
    
    int max_diff = INT_MIN;
    int min_element = a[(size_t)firstodd];
    for(size_t i = firstodd+1; i<a.size();++i)
    {
        if(a[i]%2==0 and min_element < a[i])
        {
                int current_diff = a[i]-min_element;
                max_diff = max(max_diff, current_diff);    
            
        }
        else
        {
            if(a[i]<min_element and (a[i]%2!=0))
            {
                min_element = a[i];
            }
        }
        
    }
    
    if(max_diff==INT_MIN)
    {
        return -1;
    }
    return max_diff;
    

}

int main()
{
    vector<int> a = {1,2,3,4,5,6};
    cout<<maxDifferenceOddEven(a)<<endl;
    return 0;
}