/**
 * @file GlobalAndLocalInversions.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/global-and-local-inversions/
 * @date 2022-08-02
 */



//Merge sort based solution inspired by CountInversions.cpp
class Solution {
public:
    
    long long mergeAndCount(vector<int> &nums, int startL, int endL, int startR, int endR) {
        int i = startL, j = startR;
        long long count = 0, k = 0;
        long long arr[endR - startL + 1];
        
        while(i <= endL && j <= endR) {
            if(nums[i] > nums[j]) {
                count += endL - i + 1;
                arr[k++] = nums[j++];
            } else {
                arr[k++] = nums[i++];
            }
        }
        
        while(i <= endL) {
            arr[k++] = nums[i++];
        }
        
        while(j <= endR) {
            arr[k++] = nums[j++];
        }
        
        for(int m = startL, l = 0; m <= endR && l < k; m++, l++) {
            nums[m] = arr[l];
        }
        
        return count;
    }
    
    long long globalCountHelper(vector<int> &nums, int start, int end) {
        if(start >= end) {
            return 0;
        }
        
        long long mid = start + ((end - start) / 2);
        long long LInversions = globalCountHelper(nums, start, mid);
        long long RInversions = globalCountHelper(nums, mid + 1, end);
        long long Count = mergeAndCount(nums, start, mid, mid + 1, end);
        
        return LInversions + RInversions + Count;
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        long long globalCount = 0, localCount = 0;
                
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                localCount++;
            }
        }
        
        
       globalCount = globalCountHelper(nums, 0, nums.size() - 1);

        
        cout << globalCount << " " << localCount;
        if(localCount == globalCount) {
            return true;
        }
        
        return false;
    }
};




//Intuition based approach 

//Since we have to just find whether the number of local inversions
//are same as global inversions or not, we can actually avoid the 
//work of calculating each. Also, we need to keep in mind the fact that
//problem mentions that if array is of size N, then it will have all elements
//from 0 till N - 1, just they are not guaranteed to be in their original
//position/index. For local inversion, any element nums[i] should be on either
//i - 1, i or i + 1 position, if there's any element which has moved more than this
//than it'll automatically have global inversions which are not local, and 
//for number of local inversions to be equal to global inversions,
//all global inversions must be local too, which is, there shouldn't be any global
//inversion which is not local, which is abs(A[i] - i) should be less than or 
//equal to i, for all i, if abs(A[i] - i) > i, we have a non-local global inversion,
//and we return false
class Solution {
public:
   
    bool isIdealPermutation(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};