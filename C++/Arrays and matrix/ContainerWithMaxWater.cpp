/*
Container with max water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

Idea:
1. The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
2. All other containers are less wide and thus would need a higher water level in order to hold more water.
3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

Link: https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/830/
Explanation: https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size()-1;
        
        int maxArea = 0;
        int minHeight = 0;
        while(i<j)
        {
            minHeight = min(height[i], height[j]);
            maxArea = max(maxArea, (j-i)*minHeight);
            if(height[i]==minHeight)
                ++i;
            else
                --j;
        }
        return maxArea;
    }
};