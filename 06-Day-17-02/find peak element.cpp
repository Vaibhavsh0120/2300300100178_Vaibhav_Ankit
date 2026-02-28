class Solution {
private: 
    // Recursive Binary Search: O(log n) time, O(log n) space (recursion stack)
    int recursive_binary_search(vector<int>& nums, int low, int high) {
        if (low == high) {
            return low; // Base case: one element left, it must be a peak
        }
        
        int mid = low + (high - low) / 2; // Avoid potential overflow
        
        // If mid element is greater than its right neighbor, a peak must exist in the left half
        // (including mid, since mid itself could be the peak)
        if (nums[mid] > nums[mid + 1]) {
            return recursive_binary_search(nums, low, mid);
        } else {
            // Otherwise, a peak must exist in the right half (excluding mid)
            return recursive_binary_search(nums, mid + 1, high);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        return recursive_binary_search(nums, 0, nums.size() - 1);
    }
};