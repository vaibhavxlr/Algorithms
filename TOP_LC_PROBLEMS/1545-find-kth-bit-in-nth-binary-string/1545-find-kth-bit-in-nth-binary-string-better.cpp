class Solution {
    vector<int> createString(int n) {
        if(n == 1) {
            return {0};
        }
        vector<int> temp = createString(n - 1);
        vector<int> ans(temp.begin(), temp.end());
        ans.push_back(1);
        for(int i = 0; i < temp.size(); i++) {
            temp[i] = !temp[i];
        }
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
public:
    char findKthBit(int n, int k) {
        vector<int> ans= createString(n);
        return '0' + ans[k - 1];
    }
};