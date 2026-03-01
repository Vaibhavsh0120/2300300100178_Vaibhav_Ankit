class Solution {
public:
    // Sliding Window Approach: O(n) time, O(1) space
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int max_w = 0;
        int num_zeros = 0;

        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                num_zeros++;
            }

            // Move left till num_zeroes are less than or equal to allowed zeros (k)
            while (num_zeros > k) {  
                if (nums[left] == 0) {
                    num_zeros--;
                }
                left++;
            }

            // Update the maximum window width
            max_w = max(max_w, right - left + 1);
        }

        return max_w;
    }
};