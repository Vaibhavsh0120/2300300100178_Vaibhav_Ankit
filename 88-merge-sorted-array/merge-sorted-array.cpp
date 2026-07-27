class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);

        std::merge(nums1.begin(), nums1.begin() + m,
            nums2.begin(), nums2.end(),
            ans.begin());

        nums1 = ans;
    }
};