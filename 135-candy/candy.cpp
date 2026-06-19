class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> Lcandies(ratings.size(), 1);

        for(int i = 1 ; i < ratings.size() ; i++) {
            if(ratings[i - 1] < ratings[i]) {
                Lcandies[i] = Lcandies[i - 1] + 1;
            }
        }

        vector<int> Rcandies(ratings.size(), 1);

        for(int i = ratings.size() - 2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i + 1]) {
                Rcandies[i] = Rcandies[i + 1] + 1;
            }
        }

        int sum = 0;

        for(int i = 0 ; i < ratings.size() ; i++) {
            sum += max(Lcandies[i], Rcandies[i]);
        }

        return sum;
    }
};