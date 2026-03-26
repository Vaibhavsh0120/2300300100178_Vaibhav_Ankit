class Solution {
public:
    void Two_Pointer_reverseString(vector<char>& s) {
        
        int low = 0;
        int high = s.size() - 1;
        int temp;

        while (low < high) {
            temp = s[low];
            s[low] = s[high];
            s[high] = temp;

            low++;
            high--;
        }
    }

    void reverseHelper(std::vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        std::swap(s[left], s[right]);
        reverseHelper(s, left + 1, right - 1);
    }

    void reverseString(std::vector<char>& s) {
        if (s.empty()) {
            return;
        }
        reverseHelper(s, 0, s.size() - 1);
    }
};