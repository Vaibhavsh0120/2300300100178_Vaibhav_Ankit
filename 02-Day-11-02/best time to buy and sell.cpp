class Solution {
public:
    // Greedy approach: O(n) time complexity, O(1) space complexity
    int maxProfit(vector<int>& prices) {
        int buy = prices[0]; // Track the minimum price seen so far
        int profit = 0;      // Track the maximum profit that can be achieved
        
        for (int i = 1; i < prices.size(); i++) {
            // Update the minimum buying price
            if (prices[i] < buy) {
                buy = prices[i];
            }
            // Update the maximum profit if selling today gives a better profit
            else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            } 
        }
        
        return profit;
    }
};