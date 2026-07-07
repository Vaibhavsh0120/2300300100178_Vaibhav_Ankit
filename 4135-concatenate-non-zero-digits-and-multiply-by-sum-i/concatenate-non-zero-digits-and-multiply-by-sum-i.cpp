class Solution {
public:
    long long sumAndMultiply(int n) {
        // safety
        if (n == 0) { 
            return 0;
        }

        long long soln = 0;

        long long sumNonZeroDigit = 0;
        
        // convert int to vector
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        // sum all digit 
        for(int i : digits) {
            if(i > 0) {
                sumNonZeroDigit += i;
                soln = soln*10 + i;
            }
        }

        // multiply soln and non zero digit sum

        return soln * sumNonZeroDigit;
    }
};