class Solution {
public:
    int solve(int i, int end, vector<int>& nums, vector<vector<int>>& dp) {
        if(end < i) {   // we can count last house, cause we remove \0 in rob fn
            return 0;
        }

        if(dp[i][end] != -1) {
            return dp[i][end];
        }

        int take = nums[i] + solve(i + 2, end, nums, dp); // take money, skip 1 house

        int nottake = solve(i + 1, end, nums, dp); // dont take money, go to next house

        return dp[i][end] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        // (0 - 2 - 4) -     even jump sequence
        int case1 = solve(0, nums.size() - 2, nums, dp);    // -2 -> remove last house(cause adjacent) and \0 (eof)

        //  - (1 - 3 - 5)    odd jump sequence
        int case2 = solve(1, nums.size() - 1, nums, dp);    // -1 -> remove \0

        return max(case1, case2);
    }
};