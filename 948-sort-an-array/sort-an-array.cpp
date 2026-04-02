class Solution {
public:
    void merge(vector<int>& nums, int lo, int mid, int hi) {
        vector<int> result;

        int i = lo;
        int j = mid + 1;
        while(i <= mid && j <= hi) {
            if(nums[i] < nums[j]) {
                result.push_back(nums[i]);
                i++;
            }
            else if(nums[i] > nums[j]) {
                result.push_back(nums[j]);
                j++;
            }
            else {
                result.push_back(nums[i]);
                i++;
                result.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            result.push_back(nums[i]);
            i++;
        }
        
        while(j <= hi) {
            result.push_back(nums[j]);
            j++;
        }

        int k = 0;
        for(int i = lo ; i <= hi ; i++) {
            nums[i] = result[k];
            k++;
        }

        return;
    }

    void merge_sort(vector<int>& nums, int lo, int hi) {

        if(lo >= hi) {  // single element, stop dividing
            return;
        }

        int mid = (lo + hi)/2;

        // Divide
        merge_sort(nums, lo, mid);
        merge_sort(nums, mid + 1, hi);
        // Conquer
        merge(nums, lo, mid, hi);
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};