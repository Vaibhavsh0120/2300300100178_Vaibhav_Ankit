class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // ------- BASE CONDITION
        if(amount == 0) {   // reach result
            return 0;
        }

        if(i == coins.size()) { // Out of type of coins
            return 99999;   // making sure this sequence is not min
        }
        
        // ------- DP
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // -------- TAKE , NOT TAKE
        int take = 99999;   // make sure if statement is not executed, take is not min
        if(0 <= amount - coins[i]) {
            take = 1 + solve(i, coins, amount - coins[i], dp);
        }

        int nottake = solve(i + 1, coins, amount, dp);

        // -------- RESULT
        return dp[i][amount] = min(take, nottake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount, dp);

        if(ans == 99999) {
            return -1;
        }
        return ans;
    }
};