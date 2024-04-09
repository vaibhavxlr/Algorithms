class Solution {
public:

    void helper(int start, int end, vector<int>& nums, vector<vector<int>>& solution) {
        if(start > end) {
            solution.push_back({});
            return;
        }

        helper(start + 1, end, nums, solution);
        vector<vector<int>> temp;
        for(auto it : solution) {
            temp.push_back(it);
            it.push_back(nums[start]);
            temp.push_back(it);
        }
        solution.clear();
        solution.assign(temp.begin(), temp.end());
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        helper(0, nums.size() - 1, nums, solution);
        return solution;
    }
};