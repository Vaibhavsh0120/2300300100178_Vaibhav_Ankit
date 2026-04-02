class Solution {
public:

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        int a = 0; // 0
        int b = 0; // 1
        int c = nums.size() - 1; // 2

        for(b = 0 ; b <= c ; b++){

            if(nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;
            } else if (nums[b] == 2) {
                swap(nums[c], nums[b]);
                c--;
                b--; // we dont know what came from ahead
            }

        }

    }
};