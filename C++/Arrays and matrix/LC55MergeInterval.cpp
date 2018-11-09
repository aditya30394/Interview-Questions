/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0)
            return ans;
        
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b)->bool
             {
                if(a.start < b.start)
                {
                    return true;
                }
                else if(a.start > b.start)
                {
                    return false;
                }
                else
                 {
                     return a.end<b.end;    
                 }
             });
        Interval currentInterval = intervals[0];
        
        
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start <= currentInterval.end)
            {
                currentInterval.end = max(intervals[i].end, currentInterval.end);
            }
            else
            {
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        ans.push_back(currentInterval);
        return ans;
        
    }
};