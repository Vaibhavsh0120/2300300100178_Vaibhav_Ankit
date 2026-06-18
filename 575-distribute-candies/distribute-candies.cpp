class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> mp;  //candyTime , freq

        for(int i = 0 ; i < candyType.size() ; i++) {
            mp[candyType[i]]++;
        }

        int TypesOfCandies = mp.size();
        int AllowedEating = candyType.size()/2;

        return min(AllowedEating, TypesOfCandies);
    }
};