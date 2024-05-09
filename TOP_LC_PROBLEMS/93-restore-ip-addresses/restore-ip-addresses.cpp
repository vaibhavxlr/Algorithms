class Solution {
    vector<string> ans;
    void solve(string& s, int start, int end, int depth, string sol) {
        if (start == end) {
            if (depth == 4) {
                ans.push_back(sol);
            }
            return;
        }

        if (depth == 4) {
            return;
        }

        string curr = "";

        for (int i = start; curr.size() <= 3 && i < end; i++) {
            curr += s[i];
            if (curr[0] == '0' && curr.size() > 1) {
                return;
            }
            int num = stoi(curr);
            if (num >= 0 && num <= 255) {
                if (sol == "") {
                    solve(s, i + 1, end, depth + 1, curr);
                } else {
                    solve(s, i + 1, end, depth + 1, sol + '.' + curr);
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4) {
            return {};
        }
        string sol = "";
        solve(s, 0, s.size(), 0, sol);
        return ans;
    }
};