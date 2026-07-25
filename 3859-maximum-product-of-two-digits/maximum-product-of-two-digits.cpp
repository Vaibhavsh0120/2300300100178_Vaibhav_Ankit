class Solution {
public:
    vector<int> numToArr(int n) {
        vector<int> nums;

        while(n) {
            nums.push_back(n%10);
            n /= 10;
        }

        return nums;
    }
    int maxProduct(int n) {
        
        vector<int> nums = numToArr(n);

        int lastLargest = nums[0];
        int maxProd = 0;

        for(int i = 1 ; i < nums.size() ; i++) {
            maxProd = max(maxProd, nums[i] * lastLargest);

            if(nums[i] > lastLargest) {
                lastLargest = nums[i];
            }
        }

        return maxProd;
    }
};