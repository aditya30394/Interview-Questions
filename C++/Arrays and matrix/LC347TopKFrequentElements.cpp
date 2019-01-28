/*
347. Top K Frequent Elements
Medium

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int& n:nums)
        {
            ++m[n];
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
        
        for(auto it= m.begin(); it!=m.end();++it)
        {
            pq.push(make_pair(it->second, it->first));
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};