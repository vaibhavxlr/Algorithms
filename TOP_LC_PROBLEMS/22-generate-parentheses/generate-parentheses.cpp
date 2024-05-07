class Solution {
    vector<string> ans;
    void solve(int O, int C, string curr) {
        if (O == 0 && C == 0) {
            ans.push_back(curr);
            return;
        }

        if (O > 0)
            solve(O - 1, C, curr + '(');
        if (C > 0 && C > O)
            solve(O, C - 1, curr + ')');
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, n, curr);
        return ans;
    }
};