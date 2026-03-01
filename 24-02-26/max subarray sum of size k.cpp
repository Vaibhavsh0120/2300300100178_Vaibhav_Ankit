// Implementation in Java
// Sliding Window Approach: O(n) time, O(1) space
class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        // Handle edge case where array holds fewer elements than window size k
        if (arr.length < k) {
            return -1;
        }
        
        int max_sum = 0;
        // Compute sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            max_sum += arr[i];
        }
        
        int win_sum = max_sum;
        // Slide the window by adding the new element and removing the oldest element
        for (int i = k; i < arr.length; i++) {
            win_sum += arr[i] - arr[i - k];
            max_sum = Math.max(win_sum, max_sum);
        }
        
        return max_sum;
    }
}