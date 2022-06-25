/**
 * @file 1.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
 * @date 2022-06-20
 */

class Solution {
public:
    string greatestLetter(string s) {
        
        vector<pair<bool, bool>> checker(26);
        int ansIndex = INT_MIN;
        string ans = "";
        
        for(int i = 0; i < s.size(); i++) {
            int val = toupper(s[i]) - 'A';
            if(isupper(s[i])) {
                checker[val].second = true;
            } else {
                checker[val].first = true;
            }
            if(val > ansIndex && checker[val].first && checker[val].second) {
                ansIndex = val;
            }
            
        }
        if(ansIndex == INT_MIN) {
            return ans;
        }
        ans += (ansIndex + 'A');
        return ans;
        
    }
};