class Solution {
public:
    vector<int> dp;

    int climb(int i, vector<int>& cost) {
        if(i >= cost.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = cost[i] + min(climb(i + 1, cost), climb(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);

        return min(climb(0, cost), climb(1, cost));
    }
};