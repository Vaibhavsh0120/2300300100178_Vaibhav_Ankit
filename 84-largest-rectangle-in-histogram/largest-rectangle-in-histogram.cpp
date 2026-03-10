class Solution {
public:
    // BRUTE FORCE
    int largestRectangleArea_Brute_Force(vector<int>& heights) {

        int maxArea = 0;
        
        for(int i = 0 ; i < heights.size() ; i++) {

            int min_height = heights[i];

            int area = 0;

            for(int j = i ; j < heights.size() ; j++) {
                min_height = min(min_height, heights[j]);
                int width = j - i + 1;

                area = min_height * width;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    //---------------------------------- BETTER

    vector<int> LeftSmallerValue(vector<int>& heights) {

        vector<int> ans(heights.size());
        stack<int> stk;

        for(int i = 0 ; i < heights.size() ; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            ans[i] = stk.empty() ? -1 : stk.top();

            stk.push(i);  // we need index to calculate distance
        }

        return ans;
    }

    vector<int> RightSmallerValue(vector<int>& heights) {

        vector<int> ans(heights.size());
        stack<int> stk;

        for(int i = heights.size() - 1 ; i > -1 ; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            ans[i] = stk.empty() ? heights.size() : stk.top(); // if right small dont exist, then end of height is boundary

            stk.push(i); // we need index to calculate distance
        }

        return ans;
    }

    //---------------------------------------- OPTIMAL
    // OPTIMIZED CALCULATOR
    void findLeftRightSmaller(
        vector<int>& heights,
        vector<int>& left,
        vector<int>& right
    ) {
        int n = heights.size();

        stack<int> stkL;
        stack<int> stkR;

        for(int i = 0; i < n; i++) {

            // LEFT SMALLER
            while(!stkL.empty() && heights[stkL.top()] >= heights[i]) {
                stkL.pop();
            }

            left[i] = stkL.empty() ? -1 : stkL.top();
            stkL.push(i);


            // RIGHT SMALLER
            int j = n - 1 - i;

            while(!stkR.empty() && heights[stkR.top()] >= heights[j]) {
                stkR.pop();
            }

            right[j] = stkR.empty() ? n : stkR.top();
            stkR.push(j);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;

        vector<int> left(heights.size());
        vector<int> right(heights.size());

        //better
        left = LeftSmallerValue(heights);
        right = RightSmallerValue(heights);

        //optimal
        findLeftRightSmaller(heights, left, right);

        for(int i = 0 ; i < heights.size() ; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;

            maxArea = max(maxArea, currArea);
        }

        return maxArea;

    }
};