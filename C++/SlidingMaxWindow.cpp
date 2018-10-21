/*
Sliding window problem
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Link: https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/837/

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q;
        vector<int>b;
        if(a.size()==0)
            return b;
        for(int i=0;i<k;++i)
        {
            while(!q.empty() && a[i]>=a[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(int i=k; i<a.size();++i)
        {
            b.push_back(a[q.front()]);
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            
            while(!q.empty() && a[i]>a[q.back()])
                q.pop_back();
            q.push_back(i);
                          
        }
        b.push_back(a[q.front()]);
        return b;
    }
};