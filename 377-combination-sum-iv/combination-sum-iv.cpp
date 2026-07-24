class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int target) {
        // base case
        if(target == 0) {
            return 1;
        }
        // wrong case 
         if (target < 0) {
            return 0;
         }

        // memo
        if(dp[target] != -1) {
            return dp[target];
        }

        // working
        int ways = 0;

        for (int num : nums) {
            ways += solve(nums, target - num);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return solve(nums, target);
    }
};