/*
Repeated K Times

Given a List of N number a1,a2,a3........an, You have to find smallest number from the List that is repeated in the List exactly K number of times.

Input Format

First Line of Input Contain Single Value N, Size of List
Second Line of Input Contain N Space Separated Integers
Third Line of Input Contain Single Value K

Output Format

Smallest Integer Value That is Repeated Exactly K Number of Time

Constraints

0 < N < 100001
0 <= K < 100001
0 <= ai < 100001
NOTE
There Will Be Atleast One Variable Which Is Repeated K Times
*/

#include<iostream>
#include<vector>

using namespace std;
#define MAX_VALUE 100001 

int FindSmallestRepeated(vector<int> &v, int k)
{
    vector<int>count(MAX_VALUE,0);
    for(int &i: v)
    {
        ++count[i];
    }
    for(int i=0; i<MAX_VALUE;++i)
    {
        if(count[i]==k)
        {
            return i;
        }
    }
}
int main()
{
    int n,k,a;
    cin>>n;
    vector<int>v;
    int i=0;
    while(i<n)
    {   
        cin>>a;
        v.push_back(a);
        ++i;
    }
    cin>>k;
    cout<<FindSmallestRepeated(v,k)<<endl;
    return 0;
}