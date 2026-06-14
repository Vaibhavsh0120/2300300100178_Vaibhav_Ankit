class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = i + 1 ; j < matrix[0].size() ; j++) {// i+1 to stop swap back, and traverse half triangle
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse Rows
        for(int i = 0 ; i < matrix.size() ; i++) {
            int left = 0;
            int right = matrix[0].size() - 1;

            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }

        return;
    }
};