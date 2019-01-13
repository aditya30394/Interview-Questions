/*
4. Median of Two Sorted Arrays
Hard
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

https://www.youtube.com/watch?v=LPFhl65R7ww&t=1136s
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low=0, high=x;
        while(low<=high)
        {
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 - partitionX;
            
            double maxLeftX = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            double minRightX = (partitionX==x)?INT_MAX:nums1[partitionX];
            
            double maxLeftY = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            double minRightY = (partitionY==y)?INT_MAX:nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
            {
                if((x+y)&1)
                {
                    return max(maxLeftX, maxLeftY);
                }
                else
                {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                    
                }
            }
            else if(maxLeftX>minRightY)
            {
                high = partitionX-1;
            }
            else
            {
                low = partitionX+1;
            }
            
        }
    }
};
