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

        int maxProd = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                maxProd = max(maxProd, nums[i] * nums[j]);
            }
        }

        return maxProd;
    }
};