class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        // if completing circle is not even possible
        if(totalGas < totalCost) {
            return -1;
        }

        int fuel = 0;
        int ans = 0;

        for(int i = 0 ; i < gas.size() ; i++) {
            fuel += gas[i] - cost[i] ;
            if(fuel < 0) {
                fuel = 0 ;
                ans = i+1 ;
            }
        }

        return ans;
    }
};