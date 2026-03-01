class Solution {
public:
    // Max-Heap Approach: O(M*N log K) time, O(K) space
    // Note: Can be optimized to O(N log(Max-Min)) time using Binary Search on the value range.
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        priority_queue<int> maxHeap;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Push current element into the max heap
                maxHeap.push(matrix[r][c]);
                // If the heap size exceeds k, remove the largest element
                // This ensures the heap only contains the k smallest elements seen so far
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }
        
        // The top of the max heap is the kth smallest element
        return maxHeap.top();
    }
};