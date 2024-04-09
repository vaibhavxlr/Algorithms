class Solution {
public:

    // void helper(int start, int end, vector<int>& nums, vector<vector<int>>& solution) {
    //     if(start > end) {
    //         return;
    //     }


    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return {{}};
        }

        vector<int> newNums(nums.begin() + 1, nums.end());
        vector<vector<int>> temp = subsets(newNums);
        vector<vector<int>> solution;

        for(auto it : temp) {
            solution.push_back(it);
            vector<int> s3t(it.begin(), it.end());
            s3t.push_back(nums[0]);
            solution.push_back(s3t);
        }

        return solution;
    }
};