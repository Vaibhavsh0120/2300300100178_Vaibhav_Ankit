class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int amount, vector<int>& coins) {
        // base c
        if(amount == 0) {
            return 1;
        }

        if(i == coins.size()) {
            return 0;
        }

        // dp
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // working
        int take = 0;
        if(coins[i] <= amount) {
            take = solve(i, amount - coins[i], coins);
        }

        int notTake = solve(i + 1, amount, coins);

        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins);
    }
};