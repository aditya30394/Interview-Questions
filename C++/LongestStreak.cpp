/*

Longest consecutive sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

First turn the input into a set of numbers. That takes O(n) and then we can ask in O(1) whether we have a certain number.

Then go through the numbers. If the number x is the start of a streak (i.e., x-1 is not in the set), then test y = x+1, x+2, x+3, ... and stop at the first number y not in the set. The length of the streak is then simply y-x and we update our global best with that. Since we check each streak only once, this is overall O(n). This ran in 44 ms on the OJ, one of the fastest Python submissions.
Link : https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/833/ 
Leetcode #128

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 1;
        for(int n: nums)
        {
            if(record.find(n) == record.end()) {continue;}
            record.erase(n);
            int prev = n-1;
            int next = n+1;
            
            while(record.find(prev)!=record.end()){record.erase(prev); --prev;}
            while(record.find(next)!=record.end()){record.erase(next); ++next;}
            res = max(res, next - prev - 1);
        }
        return res;
    }
};