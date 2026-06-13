class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(!isalpha(s[left])) { // if left char is not alphabet
                left++;
                continue;
            }
            else if(!isalpha(s[right])) {   // if right char is not alphabet
                right--;
                continue;
            }
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};