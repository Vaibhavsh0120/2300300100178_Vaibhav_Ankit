class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return; // EDGE CASE: IF EMPTY

        k %= n;  // EDGE CASE: IF K > N

        vector<int> result(n);

        for (int i = 0; i < n; i++) {   // KEEP COUNTING TILL N ARE ADDED
            result[i] = nums[(n - k + i) % n]; // AUTO GO BACK K TIMES AND THEN KEEP MOVING 1 STEP FORWARD AT A TIME
        }

        nums = result;
    }
};