class Solution {
public:
    bool check(int num) {
        int n = num;

        while(0 < n) {
            int digit = n % 10;
            n /= 10;

            if(digit == 0 || num % digit != 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> soln;

        for(int i = left ; i <= right ; i++) {
            if(check(i)) {
                soln.push_back(i);
            }
        }

        return soln;
    }
};