class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ln=prices.size(), totalProfit=0;
        if(ln == 0)
            return 0;
        for(int i=0; i<ln-1; i++) {
            if(prices[i] < prices[i+1])
                totalProfit += prices[i+1] - prices[i];
        }
        return totalProfit;
    }
};


// 50 500 1000
// 950

// 500-50 -> 450
// 1000-500 -> 500
/// result
// 1000-50 -> 950