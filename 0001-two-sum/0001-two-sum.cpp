class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0, second = 1;

        while(first < second) {
            int sum = nums[first] + nums[second];
            if(sum == target) {
                break;
            } else if(second == nums.size() - 1) {
                first++;
                second = first + 1;
            } else {
                second++;
            }
        }
        
        return {first, second};
    }
};