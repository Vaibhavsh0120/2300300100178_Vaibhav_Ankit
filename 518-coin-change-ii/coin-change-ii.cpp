class Solution {
public:
    vector<vector<int>> dp;

    int  helper(int i, int amount, vector<int> coins) {
        // correct ans
        if(amount == 0) {
            return 1;
        }

        // end of array
        if(i == coins.size()) {
            return 0;
        }

        // memo
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // if curr coin can be used accept and try this coin again
        int take = 0;
        if(coins[i] <= amount) {
            take = helper(i, amount - coins[i], coins);
        }

        // try next coin
        int notTake = helper(i+1, amount, coins);

        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(), vector<int>(amount + 1, -1));
        return helper(0, amount, coins);
    }
};