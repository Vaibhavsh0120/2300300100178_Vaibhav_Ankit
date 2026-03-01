class Solution {
public:
    // Binary Search Approach: O(log n) time, O(1) space
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevent overflow

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] > target) {
                right = mid - 1; // Search in the left half
            } else {
                left = mid + 1; // Search in the right half
            }
        }

        // If not found, left points to the correct insertion position
        return left;        
    }
};