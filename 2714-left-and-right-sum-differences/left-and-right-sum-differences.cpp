class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int LSum = 0;
        vector<int> LVec(nums.size());

        int RSum = 0;
        vector<int> RVec(nums.size());

        int front = 0;
        int back = nums.size() - 1;

        while(front < nums.size() || -1 < back) {
            // Left Computation
            int temp = nums[front];
            LVec[front] = LSum;
            LSum += temp;
            front++;

            // Right Computation
            temp = nums[back];
            RVec[back] = RSum;
            RSum += temp;
            back--;
        }

        vector<int> result(nums.size());

        for(int i = 0 ; i < nums.size() ; i++) {
            int value = LVec[i] - RVec[i];
            value = 0 < value ? value : -value;
            result[i] = value;
        }

        return result;
    }
};