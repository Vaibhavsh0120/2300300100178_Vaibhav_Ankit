class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int start = 0;
        int end = people.size() - 1;
        int boats = 0;

        while (start <= end) {
            // check if thin + fat ass can go together
            if (people[start] + people[end] <= limit)
                start++;

            // else send only fat ass
            end--;
            // only atmost 2 people can go at a time
            boats++;
        }

        return boats;
    }
};