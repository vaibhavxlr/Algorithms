/**
 * @file PascalsTriangle.cpp
 * @author vaibhavxlr@gmail.com
 * @brief https://leetcode.com/problems/pascals-triangle/
 * @date 2022-06-29
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // ans.push_back({1});
        // ans.push_back({1, 1});
        
        for(int i = 0; i < numRows; i++) {
            int j = 0;
            vector<int> temp;
            while(j <= i) {
                if(j == 0 || j == i) {
                    temp.push_back(1);
                } else  {
                    int index = i - 1;
                    temp.push_back(ans[index][j - 1] + ans[index][j]);                    
                }
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};