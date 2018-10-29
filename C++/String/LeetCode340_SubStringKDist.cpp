/*
Leetcode #340

Longest Substring with At Most K Distinct Characters

Given a string S, find the length of longest substring T have at most K disting characters

Example:
S = "ecebg"
T = "ece"
*/

// Example program
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string str, int k)
{
    unordered_map<char,int>dict;
    int s=0,e=0,maxLen=0;
    
    while(e<str.size())
    {
        char c = str[e];
        if(dict.find(c)==dict.end())
        {
            dict[c]=1;    
        }
        else
        {
            ++dict[c];    
        }
        
        while(dict.size()>k)
        {
            c = str[s];
            if(--dict[c]==0)
                dict.erase(c);
            ++s;    
        }
        maxLen = max(maxLen, e-s+1);
        ++e;
    }
    return maxLen;
}    
int main()
{
  std::string s("ecebg");
  cout<<lengthOfLongestSubstringKDistinct(s,2);
  
}
