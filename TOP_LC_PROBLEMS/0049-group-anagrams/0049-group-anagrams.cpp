class Solution {
private:
    void customSort(string& temp) {
        vector<int> arr(26, 0);
        int index = 0, j = 0;

        for (int i = 0; i < temp.size(); i++) {
            arr[temp[i] - 'a']++;
        }

        while (j < arr.size()) {
            if (arr[j] == 0) {
                j++;
            } else {
                temp[index++] = 'a' + j;
                arr[j]--;
            }
        }
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (auto str : strs) {
            string temp = str;
            customSort(temp);
            mp[temp].push_back(str);
        }

        for (auto items : mp) {
            ans.push_back(items.second);
        }

        return ans;
    }
};