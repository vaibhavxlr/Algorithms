class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        if(nums.size() < 3) {
            return;
        }
        for(int i = 0; i <= nums.size() / 2 && ans.size() < nums.size(); i++) {
            ans.push_back(nums[i]);
            int n = nums.size() - 1 - i;
            if(i < n) {
                ans.push_back(nums[n]);
            }
        }


       for(int i = 0; i < ans.size(); i++) {
           nums[i] = ans[i];
       }
    }
};