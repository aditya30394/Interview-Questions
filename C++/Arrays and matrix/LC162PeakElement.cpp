/*
162. Find Peak Element
Medium

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
*/

// https://youtu.be/HtSuA80QTyo?t=937

// complex solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid=0;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if(isPeak(mid, nums))
                return mid;
            
            int lowVal = (mid-1)>=0?nums[mid-1]:INT_MIN;
            int highVal = (mid+1)<nums.size()?nums[mid+1]:INT_MIN;
        
            if(lowVal == max(lowVal, highVal))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return 0;
    }
    
    bool isPeak(int index, vector<int>& nums)
    {
        int low = (index-1)>=0?nums[index-1]:INT_MIN;
        int high = (index+1)<nums.size()?nums[index+1]:INT_MIN;
        
        if(low<nums[index] and nums[index]>high)
            return true;
        
        return false;
    }
};


int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid=0;
        
        while(low<high)
        {
            mid = (low+high)/2;
            
            if(nums[mid]>nums[mid+1])
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
