/*
Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

Link: https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        
        unordered_map<char,int>map;
        for(char c: t)
        {
            map[c]=map[c]+1;
        }
        
        int counter = map.size();
        
        int begin=0,end=0;
        
        int head = 0, len = INT_MAX;

        while(end < s.length()){
            char c = s[end];
            if( map.find(c) != map.end())
            {
                map[c] = map[c]-1;
                if(map[c]==0) 
                {
                    --counter;
                }
            }
            
            end++;
            
            while(counter == 0)
            {
                char tempc = s[begin];
                if(map.find(tempc) != map.end())
                {
                    ++map[tempc];
                    if(map[tempc] > 0)
                    {
                        ++counter;
                    }
                }
                if(end-begin < len){
                    len = end - begin;
                    head = begin;
                }
                begin++;
            }
            
        }
        if(len == INT_MAX) return "";
        return s.substr(head, len);
    }
};