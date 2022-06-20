/**
 * @file ValidParantheses.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/valid-parentheses/
 * @date 2022-06-16
 */

class Solution {
public:
    bool isValid(string s) {
        //if there are odd numbers of characters
        if (s.size() % 2 != 0) {
            return false;
        }
        
        stack<char> st;
        int i = 0;
        
        while (i < s.size()) {
            if(st.empty()) {
               st.push(s[i]);
            } else {
                if(s[i] == ')' && st.top() != '(') {
                    return false;
                } else if(s[i] == '}' && st.top() != '{') {
                    return false;
                } else if(s[i] == ']' && st.top() != '[') {
                    return false;
                } else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    st.push(s[i]);
                } else {
                    st.pop();
                }
            }
            i++;
        }

        return st.empty();
        
    }
};