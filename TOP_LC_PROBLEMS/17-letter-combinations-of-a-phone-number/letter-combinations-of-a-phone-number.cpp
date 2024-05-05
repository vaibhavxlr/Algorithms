
class Solution {
    // vector<string> sol;
    std::map<char, std::string> mp;

    vector<string> solve(string digits, int start, int end) {
        if(start == end) {
            return {""};
        }

        vector<string> ans = solve(digits, start + 1, end);

        string corr = mp[digits[start]];

        vector<string> newAns;

        for(int i = 0; i < corr.size(); i++) {
            for(auto str : ans) {
                newAns.push_back(corr[i] + str);
            }
        }

        return newAns;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

       return solve(digits, 0, digits.size()); 
    }
};