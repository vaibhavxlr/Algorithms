class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> set;
       int maxOverallCount = 0;

       for(int num : nums) {
           set.insert(num);
       }
       
       for(int num : nums) {
           if(set.find(num - 1) == set.end()) {
               int val = num;
               int count = 0;
               while(set.find(val) != set.end()) {
                   count++;
                   val++;
               }
               maxOverallCount = max(maxOverallCount, count);
           }
       }

       return maxOverallCount;
    }
};