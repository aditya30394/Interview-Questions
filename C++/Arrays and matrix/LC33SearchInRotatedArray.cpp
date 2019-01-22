/*
33. Search in Rotated Sorted Array
Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

// Explanation is here: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        int mid;
        while(l<=h)
        {
            mid = l+(h-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[l]<=nums[mid])//first half is sorted
            {
                if(nums[l]<=target and target<=nums[mid])
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(nums[mid]<=target and target<=nums[h])
                {
                    l = mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};

