/*
https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/7270143/best-optimal-sol-beats-similar-to-striver-s-sol
*/

class Solution {
public:
    // Binary Search Approach: O(log n) time, O(1) space
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target falls in the sorted left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1; // Otherwise, target must be in the right half
                }
            }
            // If left half is not sorted, the right half must be sorted
            else {
                // Check if target falls in the sorted right half
                if (nums[high] >= target && target >= nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1; // Otherwise, target must be in the left half
                }
            }
        }
        
        return -1; // Target not found
    }
};