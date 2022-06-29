/**
 * @file NextPermutation.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/next-permutation/
 * @date 2022-06-30
 */


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool foundPerm = false;
        
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {     
                sort(nums.begin() + i, nums.end());
                int requiredInd = i;
                while(nums[i - 1] >= nums[requiredInd]){
                    requiredInd++;
                }
                swap(nums[i-1], nums[requiredInd]);
                foundPerm = true;
                break;
            }
        }
        
        if(!foundPerm) {
            reverse(nums.begin(), nums.end());
        } 
        
    }
};