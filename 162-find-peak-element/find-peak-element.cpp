class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int mid;

        while(l < r) {
            mid  = l + (r - l)/2; // find mid element

            if(nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};