class Solution {
public:
    bool kyaBanana(int mid, vector<int> piles, int h) {
        long long hourTaken = 0;

        for (int banana : piles) {
            hourTaken += banana / mid;

            if (banana % mid != 0) {
                hourTaken++;
            }

            if (hourTaken > h) {
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1; // mini 1 banana
        int right = *max_element(piles.begin(), piles.end()); // max banana speed possible

        while(left < right) {
            int mid = left + (right - left)/2;

            if(!kyaBanana(mid, piles, h)) { // if unable to eat banana increase speed
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};