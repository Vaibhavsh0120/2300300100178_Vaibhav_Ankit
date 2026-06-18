class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int moneySpent = 0;

        int freeCandy = 0; // 0 - 1st paid | 1 - 2nd paid | 2 - 3rd free

        for(int i = cost.size() - 1; i >= 0 ; i--) {
            if(freeCandy < 2) { // paid candy
                moneySpent += cost[i];
            }
            // Free Candy, dont take cost

            // next candy type
            freeCandy = (freeCandy + 1) % 3;
        }

        return moneySpent;
    }
};