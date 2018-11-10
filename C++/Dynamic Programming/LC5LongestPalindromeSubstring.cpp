/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        if(s.length()==0)
            return ans;
        int n = s.length();
        
        int start=0, maxLen=1;
        
        for(int i=0;i<n;++i)
        {
            int l1 = expandAlongCenter(s,i,i);
            int l2 = expandAlongCenter(s,i,i+1);
            int len = max(l1,l2);
            if(len>maxLen)
            {
                maxLen=len;
                start = i-(len-1)/2;
            }
        }
        
        return s.substr(start,maxLen);
    }
    int expandAlongCenter(string&s, int l, int r)
    {
        while(l>=0 and r<s.length() and s[l]==s[r])
        {
            --l;
            ++r;
        }
        return r-l-1;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        if(s.length()==0)
            return ans;
        int n = s.length();
        vector<vector<bool>> table(n, vector<bool>(n,false));
        
        for(int i=0;i<n;++i)
            table[i][i]=true;
        
        int start=0, maxLen=1;
        
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1]=true;
                start = i;
                maxLen=2;
            }
        }
        
        for(int l=3;l<=n;++l)
        {
            for(int i=0;i<n-l+1;++i)
            {
                int j = i+l-1;
                
                if(table[i+1][j-1] and s[i]==s[j])
                {
                    table[i][j]=true;
                    if(l>maxLen)
                    {
                        start=i;
                        maxLen=l;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};

