class Solution {
public:
    // Two pointer approach: O(n) time, O(1) space
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Pointer to place the next non-zero element
        
        for (int i = 0; i < nums.size(); i++) {
            // Find a non-zero element and swap it with the element at index j
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};