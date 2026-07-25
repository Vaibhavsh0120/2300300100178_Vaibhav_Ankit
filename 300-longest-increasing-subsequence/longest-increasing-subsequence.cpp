class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int prevLIndex, vector<int>& nums) {
        // base case
        if(i == nums.size()) {
            return 0;
        }

        // memo
        if(dp[i][prevLIndex + 1] != -1) {
            return dp[i][prevLIndex + 1];
        } 

        // notTake
        int notTake = solve(i + 1, prevLIndex, nums);

        // check if in strictly increasing
        int take = 0;
        if(prevLIndex == -1 || nums[prevLIndex] < nums[i]) {
            take = 1 + solve(i + 1, i, nums);
        }

        // prevLIndex + 1 for safety from init -1
        return dp[i][prevLIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(0, -1, nums);
    }
};