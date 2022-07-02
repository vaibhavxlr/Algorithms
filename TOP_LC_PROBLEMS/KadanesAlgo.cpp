/**
 * @file KadanesAlgo.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/maximum-subarray/
 * @date 2022-07-02
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int maxOverall = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            curMax += nums[i];
            maxOverall = max(maxOverall, curMax);
            curMax = max(curMax, 0);
        }
        return maxOverall;
    }
    
};