class Solution {
public:
    static bool compair(string a, string b) {
        // checking which sum will result in more
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> digits;

        for(int i : nums) {
            digits.push_back(to_string(i));
        }

        // decreasing order
        sort(digits.begin(), digits.end(), compair);

        // Handle all zeros if even after decreasing 0 is at first
        if (digits[0] == "0") {
            return "0";
        }

        string ans;

        for(string s : digits) {
            ans += s;
        }

        return ans;
    }
};