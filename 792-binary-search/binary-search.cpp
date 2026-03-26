class Solution {
public:
    int simple_search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }

    int helper(vector<int>& nums,int i, int j, int target) {
        if (i > j) {
            return -1;
        }

        int mid = i + (j - i)/2;

        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] > target) {
            return helper(nums, i, mid - 1, target);
        }
        else {
            return helper(nums, mid + 1, j, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};
