class Solution {
public:
    vector<int> dp;
            // added consts as we are sending temp string, not normal string
    bool isPalindrome(string &s, int i, int j) {
        int left = i;
        int right = j;

        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    int countPartition(int i, string &s) {
        // no more possible partition after string end
        if(i == s.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int minCost = INT_MAX; // no of partition

        // find largest possible palindome for current partiton starting
        for(int j = i ; j < s.size() ; j++) {
                    // startIdx, endIdx
            if(isPalindrome(s, i, j)) {
                int cost = 1 + countPartition(j + 1, s); // start finding next partition
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string &s) {
        dp.assign(s.size(), -1);

                    // startIdx, string
        return countPartition(0, s) - 1; // minCuts = no of partitions - 1
    }
};