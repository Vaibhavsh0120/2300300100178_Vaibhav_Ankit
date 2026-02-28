class Solution {
public:
    // Kadane's Algorithm: O(n) time complexity, O(1) space complexity
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Initialize to smallest possible integer
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            // Update maxSum if current sum is greater
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            // If current sum drops below zero, reset it since it won't contribute to a maximum subarray
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};