class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, vector<int>& arr, int sum) {
        if (sum == 0)
            return true;

        if (i == arr.size() || sum < 0)
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool take = solve(i + 1, arr, sum - arr[i]);
        bool notTake = solve(i + 1, arr, sum);

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        // num sum = S 
        // subset 1 sum (S1) = S/2
        // subset 2 sum (S2) = S1 = S/2
        // EXACTLY SAME AS = https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

        double sum = 0;
        for(int i : nums) {
            sum += i;
        }
        //to find subset in the num
        sum = (double)sum/2;

        // eg 10.5
        if(sum - (int)sum != 0) {
            return false;
        }

        // memeo init
        dp.assign(nums.size(), vector<int>(sum + 1, -1));

        return solve(0, nums, sum);
    }
};