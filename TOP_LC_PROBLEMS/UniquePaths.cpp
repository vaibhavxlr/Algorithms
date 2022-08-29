/**
 * @file UniquePaths.cpp
 * @author (vaibhavxlr@gmail.com)
 * @brief https://leetcode.com/problems/unique-paths/
 * @date 2022-08-29
 */

//simple top-down dp/memoization
class Solution {
    public:
        int uniquePathHelper(int stRow, int enRow, int stCol, int enCol, int dp[101][101]) {

            if (stRow == enRow || stCol == enCol) {
                dp[stRow][stCol] = 1;
                return 1;
            }

            if (dp[stRow][stCol]) {
                return dp[stRow][stCol];
            }
            int x = uniquePathHelper(stRow + 1, enRow, stCol, enCol, dp);
            int y = uniquePathHelper(stRow, enRow, stCol + 1, enCol, dp);
            dp[stRow][stCol] = x + y;
            return x + y;
        }
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                dp[i][j] = 0;
            }
        }
        return uniquePathHelper(0, m - 1, 0, n - 1, dp);
    }
};