class Solution {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const vector<T>& vec) const {
            size_t hasher = 0;
            for(auto& val : vec) {
                hasher ^= hash<T>()(val) + 0x9e3779b9 + (hasher << 6) + (hasher >> 2);
            }
            return hasher;
        }
    };
    vector<vector<int>> ans;
    unordered_set<vector<int>, VectorHash<int>> s;
    void solve(vector<int>& candidates, int target, vector<int> curr) {
        if (target <= 0) {
            sort(curr.begin(), curr.end());
            if (target == 0 && s.find(curr) == s.end()) {
                ans.push_back(curr);
                s.insert(curr);
            }
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, target, curr);
        return ans;
    }
};