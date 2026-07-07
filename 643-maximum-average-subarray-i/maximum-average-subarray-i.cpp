class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int currSum = 0;

        // window fit
        for(int i = 0 ; i < k ; i++) {
            currSum+=nums[i];
        }

        maxSum = max(maxSum, currSum);

        for(int right = k ; right < nums.size() ; right++) {
            // update window sum
            currSum += nums[right];
            currSum -= nums[right-k];

            // check max
            maxSum = max(maxSum, currSum);
        }

        return (double)maxSum/k;

    }
};