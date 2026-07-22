class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceYet = prices[0];
        int maxP = 0;

        for(int i = 0 ; i < prices.size() ; i++) {
            minPriceYet = min(minPriceYet, prices[i]);
            int profit = prices[i] - minPriceYet;
            maxP = max(maxP, profit);
        }

        return maxP;
    }
};