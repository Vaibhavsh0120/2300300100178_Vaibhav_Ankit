class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        vector<int> result(totalSize, 0);

        int i = 0, j = 0, k = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                result[k] = nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                result[k] = nums2[j];
                j++;
            }
            else {
                result[k] = nums1[i];
                i++;
                k++;
                result[k] = nums2[j];
                j++;
            }
            k++;
        }

        while(i < nums1.size()) {
            result[k] = nums1[i];
            i++;
            k++;
        }

        while(j < nums2.size()) {
            result[k] = nums2[j];
            j++;
            k++;
        }

        // Calculate median

        if(result.size() % 2 == 0) {
            double mid1 = result[result.size() / 2];
            double mid2 = result[(result.size() / 2) - 1];
            return (mid1 + mid2) / 2;
        } 
        else {
            int mid = result[result.size() / 2];
            return mid;
        }
    }
};