class Solution {
public:
    int profit(int mini, int i, vector<int>& prices, int maxPrt) {
        if(i == prices.size()) {
            return maxPrt;
        }

        int curPrt = prices[i] - mini;
        maxPrt = max(maxPrt, curPrt);
        mini = min(mini, prices[i]);

        return profit(mini, ++i, prices, maxPrt);
    }

    int maxProfit(vector<int>& prices) {
        return profit(prices[0], 1, prices, 0);

    }
};