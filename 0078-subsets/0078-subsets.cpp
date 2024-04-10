class Solution {
private:
    void helper(int start, int end, vector<int>& nums, vector<int> temp,
                vector<vector<int>>& solution) {
        if (start == end) {
            solution.push_back(temp);
            return;
        }

        helper(start + 1, end, nums, temp, solution);
        temp.push_back(nums[start]);
        helper(start + 1, end, nums, temp, solution);
    }

public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> temp;
        helper(0, nums.size(), nums, temp, solution);
        return solution;
    }
};