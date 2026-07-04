class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totalEdge = 0;

        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size(); j++) {
                // if current is island
                if(grid[i][j] == 1) {
                    int edge = 4;

                    // if left is island
                    if(i != 0 && grid[i-1][j] == 1) {
                        edge -= 2;
                    }

                    // if top is island
                    if(j != 0 && grid[i][j-1] == 1) {
                        edge -= 2;
                    }

                    totalEdge += edge;
                } 
            }
        }

        return totalEdge;
    }
};