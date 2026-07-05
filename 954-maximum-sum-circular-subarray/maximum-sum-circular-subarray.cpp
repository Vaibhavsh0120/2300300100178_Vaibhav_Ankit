class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadane’s Algorithm
        int totalSum = nums[0];

        int maxCurr = nums[0];
        int maxSum = nums[0];

        int minCurr = nums[0];
        int minSum = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++) {
            totalSum += nums[i];

            maxCurr = max(nums[i], maxCurr + nums[i]); // restart subarray if sum decreases
            maxSum = max(maxSum, maxCurr);

            minCurr = min(nums[i], minCurr + nums[i]);
            minSum = min(minSum, minCurr);
        }

        // Safety if all negative number
        if (maxSum < 0){
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};