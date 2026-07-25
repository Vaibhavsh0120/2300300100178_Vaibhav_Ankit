class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, vector<int>& coins, int amount) {
        // base c
        if(i == coins.size()) {
            return 99999;
        }

        if(amount == 0) {
            return 0;
        }

        // dp
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // working
        int take = 99999;
        if(coins[i] <= amount) {
            take = 1 + solve(i, coins, amount - coins[i]);
        }

        int notTake = solve(i + 1, coins, amount);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(), vector<int>(amount+1, -1));

        int ans = solve(0, coins, amount);
        return ans >= 99999 ? -1 : ans;
    }
};