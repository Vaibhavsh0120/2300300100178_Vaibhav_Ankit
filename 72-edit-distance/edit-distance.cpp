class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string s1, string s2) {
        // base case

        // reach s1 end
        if(i < 0) {
            return j + 1; // we will need j + 1 insert operation to match
        }

        // reach s2 end
        if(j < 0) {
            return i + 1; // we will need i + 1 delete operation to match
        }

        // no operation needed
        if(s1[i] == s2[j]) {
            return 0 + solve(i-1, j-1, s1, s2);
        }

        // memo
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // working

        // insert
        int insert = 1 + solve(i, j-1, s1, s2);

        // delete
        int remove = 1 + solve(i-1, j, s1, s2);

        // replace
        int replace = 1 + solve(i-1, j-1, s1, s2);


        return dp[i][j] = min({insert, remove, replace});
    }
    

    int minDistance(string word1, string word2) {
        // start matching from back
        dp.assign(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(word1.size()-1, word2.size()-1, word1, word2);
    }
};