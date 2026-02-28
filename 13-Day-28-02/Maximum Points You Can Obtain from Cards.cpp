class Solution {
public:
    // Sliding Window Approach: O(k) time, O(1) space
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int l_sum = 0; // Sum of points taken from the left side
        int r_sum = 0; // Sum of points taken from the right side
        int max_sum = 0;

        // Start by taking all k cards from the left
        for (int left = 0; left < k; left++) {
            l_sum += cardPoints[left];
        }

        int left = k - 1; // Last included card on the left
        int right = n - 1; // First card to include from the right
        max_sum = l_sum;

        // Slide the window: remove one from the left and add one from the right
        for (left = k - 1; left > -1; left--) {
            l_sum -= cardPoints[left];
            r_sum += cardPoints[right];
            right--;

            max_sum = max(max_sum, l_sum + r_sum);
        }

        return max_sum;
    }
};