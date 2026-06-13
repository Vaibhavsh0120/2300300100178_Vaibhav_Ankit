class Solution {
public:
    string reversePrefix(string s, int k) {
        
        int left = 0;
        int right = k - 1; // to convert from size to index

        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};