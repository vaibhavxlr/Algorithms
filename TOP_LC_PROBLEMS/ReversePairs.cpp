/**
 * @file ReversePairs.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/reverse-pairs/
 * @date 2022-09-04
 */


//NOTE:- need to do pair count separately before and not while merging
//
class Solution {
public:
    
    int merge(vector<int>& nums, int lLow, int lHigh, int rLow, int rHigh) {
        if(lLow > lHigh || rLow > rHigh) {
            return 0;
        }
        int count = 0;

        //NOTE:- make sure q is initialised here and not inside the below for loop
        //that will give TLE, also we don't want to check the left side values whicha are
        //already smaller than the twice of the smallest of right side
        int q = lLow; 
        for(int p = rLow; p <= rHigh; p++) {
            while(q <= lHigh && (nums[q] <= (nums[p] * 2LL))) {
                q++;
            }
            count += lHigh - q + 1;
        }
        int i = lLow, j = rLow;
        vector<int> temp;
    
        
        while(i <= lHigh && j <= rHigh) {
            if(nums[i] > nums[j]) {
                temp.push_back(nums[j++]);
                
            } else {
                temp.push_back(nums[i++]);
            }
        }
        
        while(i <= lHigh) {
            temp.push_back(nums[i++]);
        }
        
        while(j <= rHigh) {
            temp.push_back(nums[j++]);
        }
        
        for(int p = lLow, q = 0; p <= rHigh && q < temp.size(); p++, q++) {
            nums[p] = temp[q];
        }
        return count;
    }
     
    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) {
            return 0;
        }    
        int mid = low + ((high - low) / 2);
        int x = mergeSort(nums, low, mid);
        int y = mergeSort(nums, mid + 1, high);
        int z = merge(nums, low, mid, mid + 1, high);
        return x + y + z;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};