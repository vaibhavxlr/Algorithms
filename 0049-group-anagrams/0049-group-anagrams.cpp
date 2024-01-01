class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        int index = 0;
        
        for(auto str : strs) {
            sort(str.begin(), str.end());
            mp[str].push_back(index++);
        }
        
        for(auto items: mp) {
            vector<string> temp;
            for(auto ind : items.second) {
                temp.push_back(strs[ind]);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};