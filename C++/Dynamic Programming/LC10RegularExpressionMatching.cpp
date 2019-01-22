/*
10. Regular Expression Matching
Hard

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

https://www.youtube.com/watch?v=l3hda49XcDE&index=17&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/RegexMatching.java
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> T(m+1, vector<bool>(n+1, false));
        T[0][0]=true;
        // patterns like a*b* a*b etc.
        for(int j=1;j<=n;++j)
        {
        	if(p[j-1]=='*')
        	{
        		T[0][j]=T[0][j-2];
        	}
        }

        for(int i=1;i<=m;++i)
        {
        	for(int j=1;j<=n;++j)
        	{
        		if(s[i-1]==p[i-1]||p[j-1]=='.')
        		{
        			T[i][j]=T[i-1][j-1];
        		}
        		else if(p[j-1]=='*')
        		{
        			T[i][j]=T[i][j-2];// zero instances case

        			if(s[i-1]==p[j-2] || p[j-2]=='.')
        			{
        				T[i][j] = T[i][j] | T[i-1][j];
        			}
        		}
        		else
        		{
        			T[i][j]=false;
        		}
        	}
        }

        return T[m][n];
    }
};