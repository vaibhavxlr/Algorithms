/**
 * @file MergeIntervals.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/merge-intervals/
 * @date 2022-07-21
 */

class Solution {
public:
    
    static bool sortByFunc(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), sortByFunc);
        ans.push_back(intervals[0]);
        int ansCounter = 0;
        
        for(int i = 1; i < intervals.size(); i++)  {
            if(ans[ansCounter][1] >= intervals[i][0]) {
                ans[ansCounter][1] = max(ans[ansCounter][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
                ansCounter++;
            }
        }
        
        return ans;
    }
};