#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int result = 0;
    int CurrSum = 0;
            // Prefix Sum , Count
    unordered_map<int, int> mp;
    mp[0] = 1;[]  // base conditon -- empty sub array

    for (int i = 0 ; i < nums.size() ; i++) {
        CurrSum+=nums[i];
        int diff = CurrSum - k;  // Check how much is extra from what is needed

        if (mp.count(diff)) {
            result += mp[diff];  // check if the extra is already found / can be deleted
        }

        mp[CurrSum]++;
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