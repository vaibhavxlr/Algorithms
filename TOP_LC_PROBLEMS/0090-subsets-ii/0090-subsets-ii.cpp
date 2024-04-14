class Solution {
    void helper(int start, int end, vector<int>& nums, set<vector<int>>& s,
                vector<int> temp) {
        if (start == end) {
            s.insert(temp);
            return;
        }

        helper(start + 1, end, nums, s, temp);
        temp.push_back(nums[start]);
        helper(start + 1, end, nums, s, temp);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        set<vector<int>> s;

        helper(0, nums.size(), nums, s, temp);

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};