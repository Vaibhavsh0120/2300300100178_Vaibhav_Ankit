class Solution {
public:
    // Two pointer approach for in-place modification: O(n) time, O(1) space
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case
        
        int i = 1; // Pointer for the next unique element to be placed
        
        // Iterate checking the current element with the previous one
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i - 1]) {
                nums[i] = nums[j]; // Only place it if it's strictly greater (a new unique element)
                i++;
            }
        }
        return i; // i represents the length of the array with unique elements
    }
};