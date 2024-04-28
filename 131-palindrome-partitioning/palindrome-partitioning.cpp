class Solution {
   
    vector<vector<string>> ans;

    bool isPalindrome(string str) {
        if(str.size() == 0) {
            return false;
        }
        int i = 0, j = str.size() - 1;

        while(i < j) {
            if(str[i] == str[j]) {
                i++, j--;
            } else {
                return false;
            }
        }

        return true;
    }

    void solve(int start, int end, string& s, vector<string>& curr) {
        if(start == end) {
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i = start; i < end; i++) {
            temp += s[i];
            cout << temp << endl;
            if(isPalindrome(temp)) {
                curr.push_back(temp);
                solve(i + 1, end, s, curr);
                curr.pop_back();
            }
        }
     
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(0, s.size(), s, curr);  
        return ans;  
    }
};