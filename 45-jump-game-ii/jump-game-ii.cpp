class Solution {
public:
    int dp[10001];

    int solve(vector<int>& nums, int i) {

        if(i >= nums.size() - 1) { // if reach last state stop
            return 0;
        }

        if(dp[i] != -1) {  // if already solve for this index, use answer
            return dp[i];
        }

        int ans = INT_MAX;  // min number of jumps

        for(int jump = 1; jump <= nums[i]; jump++) { // try all jumps from 1 , 2, ... possible jump from index
            if(i + jump < nums.size()) {  // Out-of-Bound Safety Net for jumps
                int res = solve(nums, i + jump); // tried that jump from the index

                if(res != INT_MAX) { // If can reach end from this index
                    ans = min(ans, 1 + res); // check if curr jump + future jumps are the answer
                }
            }
        }

        return dp[i] = ans;  // save the answer form current jump (if not reachable from here then INT_MAX)
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); // set dp to -1
        return solve(nums, 0);
    }
};