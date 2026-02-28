class Solution {
public:
    // Two Pointer Approach: O(n) time, O(1) space
    int maxArea(vector<int>& height) {
        int i = 0; // Left pointer
        int j = height.size() - 1; // Right pointer
        int res = 0; // Maximum area

        while (i < j) {
            // Calculate current area and update max area
            res = max(res, (j - i) * min(height[i], height[j]));
            
            // Move the pointer pointing to the shorter line to potentially find a taller line
            if (height[i] < height[j]) i++;
            else j--;
        }

        return res;
    }
};
