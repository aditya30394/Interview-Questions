/*
LeetCode 30 substring-with-concatenation-of-all-words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []

Link:https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.length()==0 || words.size()==0)
            return ans;
        
        unordered_map<string, int> table,reference;
        
        int word_size = words[0].length();
        int window_size = 0;
        
        for(string word:words)
        {
            window_size+=word.length();
            ++table[word];
        }
        
        if(s.length()<window_size)
            return ans;
        
        reference = table;
        for(int i=0;i<word_size;++i)
        {
            int begin=i,end=i,counter=table.size();
            table=reference;
            while(end+word_size-1<s.length())
            {
                string laststr = s.substr(end,word_size);
                if(table.find(laststr)!=table.end())
                {
                    --table[laststr];
                    if(table[laststr]==0)
                        --counter;
                }
                
                end = end+word_size;
                
                while(counter==0)
                {
                    if(end-begin==window_size)
                    {
                        ans.push_back(begin);
                    }
                    
                    string beginstr = s.substr(begin,word_size);
                    if(table.find(beginstr)!=table.end())
                    {
                        ++table[beginstr];
                        if(table[beginstr]>0)
                            ++counter;
                    }
                    begin=begin+word_size;
                }
            }
        }
        return ans;
    }
};