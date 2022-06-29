/**
 * @file NextPermutation.cpp
 * @author vaibhavxlr@gmail.com
 * @brief  https://leetcode.com/problems/next-permutation/
 * @date 2022-06-30
 */
//smarter solution of next permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        //move from the back and find where monotonicity of the array breaks
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        //find the smallest element which is bigger than the one at 'i'
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j >= i && nums[i] >= nums[j]) {
                j--;
            }
            //swap the element on 'j' with 'i'
            swap(nums[i], nums[j]);
        }
     
        //sort the array from i + 1
        sort(nums.begin() + i + 1, nums.end());
    }
};