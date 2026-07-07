class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int currSum = 0;

        int right = 0;
        int left = 0;

        while(right < k) {
            currSum += nums[right];
            right++;
        } 

        maxSum = max(maxSum, currSum);

        while(right < nums.size()) {
            currSum += nums[right];
            currSum -= nums[left];

            left++;
            right++;

            maxSum = max(maxSum, currSum);
        }

        return (double)maxSum/k;
    }
};