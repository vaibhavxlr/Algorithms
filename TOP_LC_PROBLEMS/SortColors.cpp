/**
 * @file SortColors.cpp
 * @author (vaibhavxlr@gmail.com)
 * @date 2022-06-02
 * @brief https://leetcode.com/problems/sort-colors/
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid, low, high;
        low = mid = 0; 
        high = nums.size() - 1; 
        
        //1)smallest element, if there, will always be  at the starting of the array
        //2)highest element, if there, will always be at the ending of the array
        //3)element in between of smallest and highest, can be from starting till the end
        //  depending on the case whether the smallest and the largest exist or not
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[mid] == 0) {
                //if mid position has a 0, it means it is not mid's position and hence be   
                //incremented, also since we found one low, even low's position should be
                //incremented
                swap(nums[mid++], nums[low++]);
            } else if (nums[mid] == 2) {
               //if mid position has a 2 we found one high, so high's position should be 
                //decremented
                swap(nums[mid], nums[high--]);
            } else {
                //if it doesn't have 0 or 2, it means it has 1, which is fine for mid
                //mid position, so we just increment mid
                mid++;
            }
        }
        
        
    }
};