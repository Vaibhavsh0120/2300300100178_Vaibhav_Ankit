class Solution {
public:
    // Binary Search Approaches (Rows then Cols): O(log m + log n) time, O(1) space
    // Equivalent to O(log(m * n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bot = matrix.size() - 1;

        // Binary search to find the potential row
        while (top <= bot) {
            int mid = top + (bot - top) / 2;

            if (matrix[mid][0] <= target && matrix[mid].back() >= target) {
                // The target is within the range of this row
                break;
            } else if (matrix[mid][0] > target) {
                bot = mid - 1; // Target must be in rows above this
            } else {
                top = mid + 1; // Target must be in rows below this
            }
        }

        // Potential row is mid (or bounded appropriately)
        // Since we broke from the loop above, the target row is between top and bot.
        // It's safer to just pick a valid row bounded by bottom/top, but here `(top + bot) / 2` 
        // will give us the valid mid row if we broke out of the loop.
        if (top > bot) {
            return false; // Row not found
        }
        
        int row = top + (bot - top) / 2;

        int left = 0;
        int right = matrix[row].size() - 1;

        // Binary search within the identified row
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;        
    }
};