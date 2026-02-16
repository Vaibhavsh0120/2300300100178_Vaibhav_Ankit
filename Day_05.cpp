#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Day_05 02 - 242. Valid Anagram
bool isAnagram(string s, string t) {

    if(s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> mp1;

    for(char ch : s){
        mp1[ch]++;
    }

    unordered_map<char, int> mp2;

    for(char ch : t){
        mp2[ch]++;
    }

    bool flag = true;
    for(auto &it : mp1) {
        if(mp1[it.first] != mp2[it.first]) {
            flag = false;
        }
    }

    return flag;
}

// DAY_05 01 - 217. Contains Duplicate
bool containsDuplicate_BruteForce(vector<int>& nums) {  // O(N^2)
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

bool containsDuplicate_Sorting(vector<int>& nums) {    // O(nLogn)
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

bool containsDuplicate_HashMap(vector<int>& nums) {     //O(n)
    unordered_map<int,int> mp;

    for(int i = 0 ; i < nums.size() ; i++){
        if(mp.count(nums[i])) {
            return true;
        } else {
            mp[nums[i]]++;
        }
    }

    return false;
}

int main(){
    
    return 0;
}