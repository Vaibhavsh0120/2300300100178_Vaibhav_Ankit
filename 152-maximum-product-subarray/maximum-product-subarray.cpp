class Solution {
public:
    // kadane's algo modified
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for(int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(currMax * nums[i], nums[i]);
            currMin = min(currMin * nums[i], nums[i]);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};