class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // directly changing actual array can change future a[i][j] values
        vector<vector<int>> work = matrix; 

        for(int i = 0 ; i < work.size() ; i++) {
            for (int j = 0 ; j < work[0].size() ; j++) {
                
                // if element is 0
                if(work[i][j] == 0) {

                    // set the whole row 0 in actual array
                    for(int k = 0 ; k < work[0].size() ; k++) {
                        matrix[i][k] = 0;
                    }

                    // set the whole column 0 in actual array
                    for(int l = 0 ; l < work.size() ; l++) {
                        matrix[l][j] = 0;
                    }

                }
            }
        }
        
    }
};