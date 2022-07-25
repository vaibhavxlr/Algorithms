/**
 * @file FindTheDuplicateNumber.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/find-the-duplicate-number/
 * @date 2022-07-24
 * 
 */

//Fast and slow pointer approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) { 
      if(nums.size() > 1) {
          
          int slow = nums[0]; 
          int fast = nums[nums[0]];
          
          while(slow != fast) {
              slow = nums[slow];
              fast = nums[nums[fast]];
          }
          
          fast = 0;
          
          while(slow != fast) {
              slow = nums[slow];
              fast = nums[fast];
          }
          
          return fast;
          
      }
        
      return -1;
    }
    
};

//Binary search approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 1;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count_mid = 0;
            
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] <= mid) {
                    count_mid++;
                }    
            }
            if(count_mid > mid) {
                    ans = mid;
                    end = mid - 1;
            } else {
                    start = mid + 1;
            }
            
        }
        
        return ans;
    }
};


//Sum of set bits
class Solution {
public:
    int findMaxElem(vector<int>& nums) {
       int max = INT_MIN;
       for(int i = 0; i < nums.size(); i++) {
           if(max < nums[i]) {
               max = nums[i];
           }
        }
        return max;
    }
    
    int calculateBits(int maxElem) {
        int count = 0;
        while(maxElem) {
            maxElem /= 2;
            count++;
        }
        return count;
    }
    
    int findDuplicate(vector<int>& nums) {
       int maxElem = findMaxElem(nums);
       int noOfBits = calculateBits(maxElem) + 1;
       int res = 0;
        
       for(int i = 0; i < noOfBits; i++) {
           int mask = 1 << i;
           int a = 0, b = 0;
           
           for(int i = 0; i < nums.size(); i++) {
               if(nums[i] & mask) {
                    a++;        
               }
               if(i & mask) {
                   b++;
               }
           }
           
           if(a > b) {
               res += mask;
           }
       }
       return res;
    }
};