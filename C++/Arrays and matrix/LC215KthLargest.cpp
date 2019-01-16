/*
215. Kth Largest Element in an Array
Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/


//O(nlogk) solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int small = nums.size()-k+1;
        priority_queue<int> max_heap(nums.begin(), nums.begin()+small);
        
        for(int i=small;i<nums.size();++i)
        {
            if(nums[i]<max_heap.top())
            {
                max_heap.pop();
                max_heap.push(nums[i]);
            }
        }
        return max_heap.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int> > min_heap(nums.begin(), nums.begin()+k);
        
        for(int i=k;i<nums.size();++i)
        {
            if(nums[i]>min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int p = partition(nums,l,r);
            if(p==k-1)
            {
                return nums[p];
            }
            else if(p<k-1)
            {
                l=p+1;
            }
            else
            {
                r = p-1;
            }
        }
        return INT_MAX;
    }
    
    int partition(vector<int>& nums, int l, int r)
    {
        int i=l, pivot=nums[r];
        for(int j=l;j<=r-1;++j)
        {
            if(nums[j]>pivot)
            {
                swap(nums[j], nums[i]);
                ++i;
            }
        }
        swap(nums[r], nums[i]);
        return i;
    }
};

