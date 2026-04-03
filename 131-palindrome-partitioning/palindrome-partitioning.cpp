class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int start, string s, vector<string>& curr, vector<vector<string>>& result) {

        if(start >= s.size()) {
            result.push_back(curr);
            return;
        }

        for(int end = start; end < s.size(); end++) {

            string part = s.substr(start, end - start + 1);

            if(isPalindrome(part)) {

                curr.push_back(part);

                solve(end + 1, s, curr, result);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> curr;

        solve(0, s, curr, result);

        return result;
    }
};