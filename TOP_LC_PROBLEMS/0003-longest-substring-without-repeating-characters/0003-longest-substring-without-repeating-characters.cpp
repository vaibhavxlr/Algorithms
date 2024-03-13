class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_count = 0;
        map<char, int> mp;
        int ind = -1;
        
        while(start < s.size()) {
            if(mp.find(s[start]) != mp.end()) {
                if(ind < mp[s[start]]) {
                    ind = mp[s[start]];   
                }
            } 
            mp[s[start]] = start;
            max_count = max(max_count, start - ind);
            start++;
        }
        
        return max_count;
    }
};