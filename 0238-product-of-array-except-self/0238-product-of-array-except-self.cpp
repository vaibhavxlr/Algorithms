class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fullProduct = INT_MIN;
        vector<int> ans;
        bool hasZero = false;

        for (auto& num : nums) {
            if (num == 0 && !hasZero) {
                hasZero = true;
            } else {
                if (fullProduct == INT_MIN) {
                    fullProduct = 1;
                }
                fullProduct *= num;
            }
        }

        for (auto& num : nums) {
            if (num == 0) {
                ans.push_back(fullProduct);
            } else if (hasZero) {
                ans.push_back(0);
            } else {
                int val = fullProduct / num;
                ans.push_back(val);
            }
        }

        return ans;
    }
};