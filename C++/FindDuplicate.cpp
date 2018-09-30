/*
Given an array nums containing n + 1 integers where each integer is between 
1 and n (inclusive), prove that at least one duplicate number must exist. Assume
that there is only one duplicate number, find the duplicate one.


Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

#include<iostream>
#include<vector>

using namespace std;

// Logic is slow-fast pointer that we use to detect a loop in linked list.
int findDuplicate(vector<int>& nums) 
{
    if(nums.size()>1)
    {
        int fast =0,slow=0;
        slow = nums[0];
        fast = nums[nums[0]];
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    return -1;
}

// solution by modifying the array
int findDuplicate2(vector<int>& nums) 
{
    if(nums.size()>1)
    {
        int i; 
        for (i = 0; i < nums.size(); i++) 
        { 
          if (nums[abs(nums[i])] >= 0) 
            nums[abs(nums[i])] = -nums[abs(nums[i])]; 
          else
            return  abs(nums[i]);
        } 
    }
    return -1;
}

int main()
{
    vector<int> v = {1,3,4,2,2};

    cout<<findDuplicate(v);
}