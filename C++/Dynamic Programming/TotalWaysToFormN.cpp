/***
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N'
using the sum of the given three numbers.
(allowing repetitions and different arrangements).
***/
#include <iostream>
#include <vector>
using namespace std;

unsigned int TotalWaysToFormN(unsigned int n)
{
    vector<unsigned int> ans;
    ans.resize(n+1,0);
    ans[0]=1;
    for(int i =1; i<=n; ++i)
    {
        ans[i]+=ans[i-1];
        if(i-3>=0)
        {
           ans[i]+=ans[i-3];
        }
        if(i-5>=0)
        {
            ans[i]+=ans[i-5];
        }
    }
    return ans[n];
}

int main()
{
    cout<<" N is 0: Number of ways is "<<TotalWaysToFormN(0)<<endl;
    cout<<" N is 1: Number of ways is "<<TotalWaysToFormN(1)<<endl;
    cout<<" N is 2: Number of ways is "<<TotalWaysToFormN(2)<<endl;
    cout<<" N is 5: Number of ways is "<<TotalWaysToFormN(5)<<endl;
    cout<<" N is 6: Number of ways is "<<TotalWaysToFormN(6)<<endl;
    cout<<" N is 12: Number of ways is "<<TotalWaysToFormN(12)<<endl;
    cout<<" N is 19: Number of ways is "<<TotalWaysToFormN(19)<<endl;

    return 0;
}
