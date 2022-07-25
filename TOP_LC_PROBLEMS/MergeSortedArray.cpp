/**
 * @file MergeSortedArray.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/merge-sorted-array/
 * @date 2022-07-22
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int end = nums1.size() - 1;
        int first = m - 1;
        int second = n - 1;
        
        while(end >= 0) {
            if(first >= 0 && second >= 0 && nums1[first] > nums2[second]) {
                nums1[end--] = nums1[first--];
            } else if (second >= 0) {
                nums1[end--] = nums2[second--];
            } else {
                end--;
            }
        }
        
    }
};