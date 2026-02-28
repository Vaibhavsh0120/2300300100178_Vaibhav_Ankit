class Solution {
public:
    // Sliding Window Approach: O(n) time, O(1) space
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            // If the window has more than k zeros, shrink it from the left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update the maximum length of the valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};