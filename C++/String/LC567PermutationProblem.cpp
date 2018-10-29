/*

Leetcode 567 https://leetcode.com/problems/permutation-in-string/description/

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].


*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> table;
        
        for(char c: s1)
        {
            ++table[c];
        }
        
        int begin=0,end=0,counter=table.size();
        
        while(end<s2.length())
        {
            char c = s2[end];
            
            if(table.count(c))
            {
                --table[c];
                if(table[c]==0)
                    --counter;
            }
            ++end;
            
            while(counter==0)
            {
                char c = s2[begin];
                if(end-begin==s1.length())
                {
                    return true;
                }
                
                if(table.count(c))
                {
                    ++table[c];
                    if(table[c]>0)
                        ++counter;
                }
                ++begin;
            }
        }
        return false;
    }
};