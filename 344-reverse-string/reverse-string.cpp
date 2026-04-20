class Solution {
public:
    void Reverse(int i, int j, vector<char>& s) {
        if(i > j) {
            return;
        }
        
        swap(s[i], s[j]);
        
        Reverse(++i, --j, s);
    }

    void reverseString(vector<char>& s) {
        Reverse(0, s.size() - 1, s);
        return;
    }
};