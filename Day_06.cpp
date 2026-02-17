#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int result = 0;
    int currSum = 0;

    // prefixSum → frequency
    unordered_map<int, int> mp;
    mp[0] = 1;   // base condition (empty prefix)

    for (int i = 0; i < nums.size(); i++) {

        currSum += nums[i];

        int diff = currSum - k;

        // If prefix with 'diff' exists,
        // we found subarrays summing to k
        if (mp.count(diff)) {
            result += mp[diff];
        }

        mp[currSum]++;
    }

    return result;
}


int search(vector<int>& nums, int target) {

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    
    return 0;
}