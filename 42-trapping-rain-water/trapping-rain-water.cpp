class Solution {
public:
    int trap_Brute_Force(vector<int>& height) {
        int n = height.size();
        // Left Max
        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for(int i = 1 ; i < n ; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // Right Max
        vector<int> suffixMax(n);
        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        // now we know what walls are largest at a index for left and right side
        int total = 0;

        for(int i = 0 ; i < n ; i++) {
            // when will water fill
            if(prefixMax[i] > height[i] && height[i] < suffixMax[i]) {
                total += min(prefixMax[i], suffixMax[i]) - height[i];
            }
        }

        return total;

    }

    // 2 pointer
    int trap(vector<int>& height) {
        int total = 0;

        int left = 0;
        int right = height.size() - 1;

        int lmax = -1;
        int rmax = -1;

        while(left < right) {
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);

            if(lmax < rmax) {
                total += lmax - height[left];
                left++;
            } 
            else {
                total += rmax - height[right];
                right--;
            }
        }

        return total;
    }
};