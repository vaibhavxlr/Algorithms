class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        string temp = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                  if(temp != "") {
                    sta.push(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }

        if(temp != "") {
            sta.push(temp);
        }


        s = "";
        while(!sta.empty()) {
            s += sta.top() + " ";
            sta.pop();
        }

        s.resize(s.length() - 1);

        return s;
    }
};