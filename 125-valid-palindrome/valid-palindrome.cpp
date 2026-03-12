class Solution {
public:
    bool isPalindrome(string s) {
    string complete;

    for(char c : s) {
        if(isalnum(c)) {
            complete += tolower(c);
        }
    }

    // palindrone
    int l = 0;
    int r = complete.size() - 1;

    while(l < r) {
        if(complete[l] != complete[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
    }
};