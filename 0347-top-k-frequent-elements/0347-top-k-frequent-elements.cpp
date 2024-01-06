class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elemMap;
        priority_queue<pair<int, int>> maxHeap;
        vector<int> ans;

        for(auto& a : nums) {
            elemMap[a]++;
        }

        for(auto &a : elemMap) {
            pair<int, int> temp{a.second, a.first};
            maxHeap.push(temp);
        }

        while(k > 0 && !maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return ans;
    }
};