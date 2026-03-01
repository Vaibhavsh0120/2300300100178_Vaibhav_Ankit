class Solution {
public:
    // Sorting Approach: O(n log n) time, O(1) space (excluding sort stack)
    // Note: Can be optimized to O(n) time using an unordered_set to track elements.
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end()); // Sort the array to find consecutive sequences
        
        int curr = 1;
        int longsub = 0; // Track the maximum length of consecutive elements
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) { // Ignore duplicates
                if (nums[i] == nums[i - 1] + 1) {
                    curr++; // Valid consecutive element
                } else {
                    longsub = max(longsub, curr); // End of current sequence
                    curr = 1; // Reset for the next sequence
                }
            }
        }
        
        return max(longsub, curr); // Final check comparison
    }
};