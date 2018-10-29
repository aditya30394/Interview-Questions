/*
Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

Link : https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/827
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        
        int temp = 1;
        
        for(int i=1;i<nums.size();++i)
        {   temp = temp * nums[i-1];
            output[i] = temp;
        }
        
        temp = 1;
        for(int i = nums.size()-2; i>=0;--i)
        {
            temp = temp * nums[i+1];
            output[i] = output[i] * temp;
        }
        
        return output;
    }
};


int main()
{
	vector<int> v = {1,2,3,4,5,6};
	Solution *s = new Solution();
	vector<int> output = s->productExceptSelf(v);
	for(int &i:output)
		cout<< i << " "; 
	delete s;
	return 0;
}
