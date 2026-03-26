class Solution {
public:
    int simple_fib(int n) {
        // USING STRIVER DP VID 1

        if(n <= 1) {
            return n;
        }

        int prev2 = 0;
        int prev = 1;

        for(int i = 2 ; i <= n ; i++) {
            int currFibo = prev + prev2;
            prev2 = prev;
            prev = currFibo;
        }

        return prev;
    }

    // recusion
    int fib(int n) {
        if(n <= 1) {
            return n;
        }

        return fib(n - 2) + fib(n - 1);
    }
};