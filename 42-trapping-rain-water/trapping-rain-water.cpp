class Solution {
public:
    int trap(vector<int>& height) {
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
};