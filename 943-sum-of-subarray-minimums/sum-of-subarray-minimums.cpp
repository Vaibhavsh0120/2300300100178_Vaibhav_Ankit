class Solution {
public:
    int sumSubarrayMins_Brute_Force(vector<int>& arr) {
        long long sum = 0;

        int mod = (int) (1e9 + 7);

        for(int i = 0 ; i < arr.size() ; i++) {
            int mini = arr[i];

            for(int j = i ; j < arr.size() ; j++) {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }

        return sum;
    }

    // ----------------------------------------------------------------------------

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }

            ans[i] = stk.empty() ? n : stk.top();

            stk.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }

            ans[i] = stk.empty() ? -1 : stk.top();

            stk.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long mod = (int)(1e9 + 7);

        vector<int> nse = findNSE(arr);  // next small element
        vector<int> pse = findPSE(arr);  // previous small element

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - pse[i];  // distance from prev small element
            long long right = nse[i] - i; // distance from prev small element

            sum = (sum + (arr[i] * left * right) % mod) % mod;
        }

        return sum;
    }
};