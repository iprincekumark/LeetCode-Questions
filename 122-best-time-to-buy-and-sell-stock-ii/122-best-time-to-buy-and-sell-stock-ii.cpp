class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, profit;
        if(prices.size() == 0)
            return 0;
        for(i=0; i<prices.size()-1; i++) {
            if(prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};