/**
 * @file MajorityElement2.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/majority-element-ii/
 * @date 2022-08-29
 */


//same as original Boyer Moore Majority vote algo, with two changes:-
//1) when we need to find elements occuring more than N/3 times, it is fixed that we can have at most 2 such elements
//2) here we need to go through the second pass also, to ascertain whether the picked elements are occuring more than N/3 times or not.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     
        int ele1 = 0, countEle1 = 0, ele2 = 0, countEle2 = 0;
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if (nums[i] == ele1) {
                countEle1 += 1;
            } else if (nums[i] == ele2) {
                countEle2 += 1;
            } else if (countEle2 == 0) {
                countEle2 += 1;
                ele2 = nums[i];
            } else if(countEle1 == 0) {
                countEle1 += 1;
                ele1 = nums[i];
            } else {
                countEle1--;
                countEle2--;
            }
        }
        
        countEle1 = countEle2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) {
                countEle1++;
            } else if(nums[i] == ele2) {
                countEle2++;
            }
        }
        
        if(countEle1 > n / 3) {
            ans.push_back(ele1);
        }
        
        if(countEle2 > n / 3) {
            ans.push_back(ele2);
        }
        
        return ans;
    }
};