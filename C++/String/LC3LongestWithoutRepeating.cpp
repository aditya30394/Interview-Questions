/*
Link : LC 3 https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Editorial:
https://leetcode.com/articles/longest-substring-without-repeating-characters/

Brute force

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (allUnique(s, i, j)) ans = Math.max(ans, j - i);
        return ans;
    }

    public boolean allUnique(String s, int start, int end) {
        Set<Character> set = new HashSet<>();
        for (int i = start; i < end; i++) {
            Character ch = s.charAt(i);
            if (set.contains(ch)) return false;
            set.add(ch);
        }
        return true;
    }
}
O(n3)

-------------
using set
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }
}

--------------

using sliding window

The above solution requires at most 2n steps. In fact, it could be optimized to require only n steps. Instead of using a set to 
tell if a character exists or not, we could define a mapping of the characters to its index. Then we can skip the characters 
immediately when we found a repeated character.

The reason is that if s[j] have a duplicate in the range [i, j) with index j′, we don't need to increase i little by little. 
We can skip all the elements in the range [i,j′] and let i to be j' + 1 directly.

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>(); // current index of character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}


*/

class Solution {
public:
    int lengthOfLongestSubstringSet(string str) {
       if(str.length()==0)
           return 0;
        
        unordered_set<char> s;
        int ans = INT_MIN;
        int begin=0,end=0;
        while(begin<str.length() and end<str.length())
        {
            char c = str[end];
            if(s.find(c)!=s.end())
            {
                s.erase(str[begin]);
                ++begin;
            }
            else
            {
                s.insert(c);
                ++end;
                ans=max(ans,end-begin);
            }
        }
        
         return ans;   
    }

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int begin = 0, end = 0;
        int len = 0;
        
        string ans = "";
        
        while(end < s.length()){
            char current = s[end];
            
            if(seen.count(current) == 1 && seen[current] >= begin){
                begin = seen[current] + 1;
            }
            else{
                seen[current] = end;
                end++;            
            }
            
            if(end - begin > len){
                len = end - begin;
                ans = s.substr(begin, end - begin);
            }
        }
        
        return len;
    }
};