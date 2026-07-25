class Solution {
public:
    vector<int> dp;

    int solve(int i, string &s) {
        // base case
        if(i == s.size()) {
            return 1;
        }

        if(s[i] == '0') {
            return 0;
        }

        // memo
        if(dp[i] != -1) {
            return dp[i];
        }

        // take one
        int one = solve(i + 1, s);

        // take two, if valid
        int two = 0;
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            two = solve(i + 2, s);
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        dp.assign(s.size() + 1, -1);
        return solve(0, s);
    }
};