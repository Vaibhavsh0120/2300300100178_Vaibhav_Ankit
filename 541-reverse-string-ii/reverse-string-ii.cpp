class Solution {
public:
/*
    Rephrasing the question:
    For every group of 2k characters, reverse the first k characters.

    Example:

    "onetwoten", k = 3

    we take the first group of 2k, or 6 chars: "onetwo"
    reverse the first k = 3 chars
    ignore the next k = 3 chars from this group: "eno" + "two"
    take the next group of 2k = 6 chars: "ten" (we only have 3 chars left, so take those)
    reverse the first k = 3 chars of the group: so "ten" becomes "net"
    result: "eno" + "two" + "net"
*/
    string reverseStr(string s, int k) {
        for(int i = 0 ; i < s.size() ; i = i + 2 * k) {
            int left = i;
            int right = min(i + k - 1, (int)s.size() - 1);  // Out of bound safety

            while(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};