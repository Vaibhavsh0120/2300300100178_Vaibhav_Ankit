class Solution {
public:
    // dp[i]
    // -1 -> answer for this index is not computed yet
    //  0 -> cannot reach the last index from i
    //  1 -> can reach the last index from i
    vector<int> dp;

    bool solve(int i, vector<int>& nums) {

        // If we have reached or crossed the last index,
        // then the destination is reachable.
        if (i >= nums.size() - 1) {
            return true;
        }

        // If this state is already computed,
        // return the stored result.
        if (dp[i] != -1) {
            return dp[i];
        }

        // Maximum jumps possible from current index.
        int possible_jumps = nums[i];

        // Try every jump from maximum to minimum.
        while (possible_jumps > 0) {

            // If any jump can reach the end,
            // store and return true.
            if (solve(i + possible_jumps, nums)) {
                dp[i] = 1;
                return true;
            }

            possible_jumps--;
        }

        // None of the jumps worked.
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {

        // Single element array:
        // already standing at the last index.
        if (nums.size() == 1) {
            return true;
        }

        // Initialize DP with -1 (not computed).
        dp.assign(nums.size(), -1);

        // Start recursion from index 0.
        return solve(0, nums);
    }
};