/**
 * @file MajorityElement.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/majority-element/
 * @date 2022-08-21
 */

//For other approaches check this:- 

//Single pass, most efficient approach using Boyer Moore's voting Algorithm
//NOTE:- we are not making one more pass, although, the algorithm says to have the
//second pass to ascertain majority (i.e  > N/2), i.e. because problem has 
//guaranteed that there would be one element which is present > N/2 times
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }
            if(candidate == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        
        return candidate;
    }
};