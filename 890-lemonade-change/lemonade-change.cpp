class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        for(int i : bills) {
            if(i == 5) {
                fives++;
            }

            if(i == 10) {
                tens++;
                if(fives == 0) {
                    return false;
                }
                fives--;
            }

            if(i == 20) {
                twenties++;
                if(tens >= 1 && fives >= 1) {
                    tens--;
                    fives--;
                }
                else if(fives >= 3) {
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};