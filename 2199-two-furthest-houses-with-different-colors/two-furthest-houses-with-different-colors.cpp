class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int distance = 0;

        for(int i = 0 ; i < colors.size() ; i++) {
            for(int j = i ; j < colors.size() ; j++) {
                if(j - i > distance && colors[i] != colors[j]) {
                    distance = j - i;
                }
            }
        }

        return distance;
    }
};