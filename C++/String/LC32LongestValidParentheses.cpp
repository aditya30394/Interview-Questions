/*
32. Longest Valid Parentheses
Hard

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

// The solution page is really good to understand how the 3 solution works
// 1. left and right counter - O(n) in time and O(1) in space
// 2. using stack O(n) in space and time
// 3. DP O(n) in space and time

//solution 1
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0, right=0, maxLen=0;
        
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
            {
                ++left;
            }
            else
            {
                ++right;
            }
            
            if(left==right)
            {
                maxLen=max(maxLen,2*left);
            }
            else if(right>=left)
            {
                left=right=0;
            }
        }
        
        left=right=0;
        for(int i=s.length()-1;i>=0;--i)
        {
            if(s[i]=='(')
            {
                ++left;
            }
            else
            {
                ++right;
            }
            
            if(left==right)
            {
                maxLen=max(maxLen,2*left);
            }
            else if(left>=right)
            {
                left=right=0;
            }
        }
        return maxLen;
    }
};

//solution 2 using stack

class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        stack<int>stk;
        stk.push(-1);
        
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    res=max(res, i-stk.top());
                }
            }
        }
        return res;
    }
};

// solution 3 DP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(), len=0;
        vector<int>dp(n,0);
        for(int i=1;i<n;++i)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=2+(i-2>=0?dp[i-2]:0);
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i]= 2 + dp[i-1] + ((i-dp[i-1]-2 >=0)? dp[i-dp[i-1]-2]:0);
                }
                
            }
            len=max(len,dp[i]);
        }
        return len;
    }
};
