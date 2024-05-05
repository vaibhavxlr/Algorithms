class Solution {
private:    
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int start, int target, vector<int>& curr) {
        if (target <= 0) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            solve(candidates, i, target - candidates[i], curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, 0, target, curr);
        return ans;
    }
};