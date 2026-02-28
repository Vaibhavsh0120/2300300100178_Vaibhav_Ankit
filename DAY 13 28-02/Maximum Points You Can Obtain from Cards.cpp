class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
    
            int n = cardPoints.size();
            
            int l_sum = 0;
            int r_sum = 0;
            int max_sum = 0;
    
            int left = 0;
            int right = 0;
    
            for(left = 0 ; left < k ; left++) {
                l_sum += cardPoints[left];
            }
    
            left = k - 1;
            right = n - 1;
            max_sum = l_sum;
    
            for(left = k - 1 ; left > -1 ; left--) {
                l_sum -= cardPoints[left];
                r_sum += cardPoints[right];
                right--;
    
                max_sum = max(max_sum, l_sum + r_sum);
            }
    
            return max_sum;
        }
    };