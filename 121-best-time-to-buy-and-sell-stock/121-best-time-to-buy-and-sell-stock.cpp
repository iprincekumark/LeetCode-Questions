class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, min=INT_MAX, profit=0;
        for(i=0; i<prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            }
            if(profit < (prices[i] - min))
                profit = prices[i]-min;
        }
        return profit;
    }
};