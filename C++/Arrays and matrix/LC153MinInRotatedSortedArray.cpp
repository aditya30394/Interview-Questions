/*
153. Find Minimum in Rotated Sorted Array
Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0, h = nums.size()-1,mid;
        if(nums.size()==1)
            return nums[0];
        
        if(nums[h]>nums[0])
            return nums[0];
        
        while(l<=h)
        {
            mid = l + (h-l)/2;
            
            if(nums[mid]>nums[mid+1])
            {
                return nums[mid+1];
            }
            if(nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            if(nums[0]<nums[mid])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return -1;
    }
};