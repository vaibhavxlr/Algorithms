/**
 * @file 1.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
 * @date 2022-06-20
 */
class Solution {
public:
    string greatestLetter(string s) {
       
        string ans = "";
        int hold[26]= {};
        int index = INT_MIN;
        int hasLower[26] = {};
        int hasUpper[26] = {};
        
        for(int i = 0; i < s.length(); i++) {
            char temp = toupper(s[i]);

            if(islower(s[i])) {
                hasLower[temp - 'A']++;
            } else {
                hasUpper[temp - 'A']++;
            }
            hold[temp - 'A']++;
        }
        
       for(int i = 25; i >= 0; i--) {
           if(hold[i] >= 2 && hasLower[i] > 0 && hasUpper[i] > 0){
            index = i;       
            break;
           }
       }
        
       if(index == INT_MIN) {
           return ans;
       }
       ans += (char)(65 + index); 
       return ans;
    }
};