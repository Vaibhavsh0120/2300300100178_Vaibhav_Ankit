class Solution {
public:
    int strToInt(string word, vector<int>& weights){
        int sum = 0;

        for(int i = 0; i < word.size() ; i++) {
            sum += weights[word[i] - 'a'];
        }

        return sum;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for(int i = 0 ; i < words.size() ; i++) {
            int alphaPos = strToInt(words[i], weights);
            result.push_back('z' - (alphaPos % 26));  // reverse mapping
        }

        return result;
    }
};