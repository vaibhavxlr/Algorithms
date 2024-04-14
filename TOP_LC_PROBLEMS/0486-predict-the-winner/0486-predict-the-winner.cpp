class Solution {
    bool helper(int start, int end, int player1Count, int player2Count,
                bool firstTurn, vector<int>& nums) {
        if (start == end) {
            return  firstTurn ? (player1Count + nums[start] >= player2Count) : (player1Count >= player2Count + nums[start])  ;
        }


        if (firstTurn) {
            return helper(start + 1, end, player1Count + nums[start], player2Count, !firstTurn, nums) || 
                    helper(start, end - 1, player1Count + nums[end], player2Count, !firstTurn, nums);
        }  else {
            return helper(start + 1, end, player1Count, player2Count + nums[start], !firstTurn, nums) && 
                    helper(start, end - 1, player1Count, player2Count + nums[end], !firstTurn, nums);
        }

        return false;
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(0, nums.size() - 1, 0, 0, true, nums);
    }
};