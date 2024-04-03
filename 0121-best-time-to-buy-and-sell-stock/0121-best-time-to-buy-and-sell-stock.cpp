class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int dayShareBought = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - prices[dayShareBought]);
            if(prices[i] < prices[dayShareBought]) {
                dayShareBought = i;
            }
        }
        
        return maxProfit;
    }
};