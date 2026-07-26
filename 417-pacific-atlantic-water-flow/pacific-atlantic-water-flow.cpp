class Solution {
public:
    // up, down, left, right
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1,}, {0, 1}};

    void DFS(int i, int j, vector<vector<int>>& heights, int prevCellValue, vector<vector<bool>>&Visited) {
        // safety check
        if(i < 0 || heights.size() <= i || j < 0 || heights[0].size() <= j) {
            return;
        }

        // if unable to flow or already visited
        if(heights[i][j] < prevCellValue || Visited[i][j]) {
            return;
        }

        Visited[i][j] = true;

        for(auto &dir : directions) {
            // new [i_, j_] - {up, down, left, right}
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(i_, j_, heights, heights[i][j], Visited);
        }


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // if water can go to pacific from cell or not
        vector<vector<bool>> pacificVisited(m, vector<bool>(n , false)); 

        // if water can go to atlantic from cell or not
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n , false)); 

        // Top Row and Bottom Row
        // Top Row: Pacific connected already
        // Bottom Row: Atlantic connected already

        // trying each colomn from top and bottom
        for(int j = 0 ; j < n ; j++) {
            DFS(0, j, heights, INT_MIN, pacificVisited);    // TOP ROW
            DFS(m-1, j, heights, INT_MIN, atlanticVisited); // BOTTOM ROW
        }

        // First Column and Last Column
        // First Column: Pacific connected already
        // Last Column: Atlantic connected already
        
        for(int i = 0 ; i < m; i++) {
            DFS(i, 0, heights, INT_MIN, pacificVisited);    // FIRST COLUMN
            DFS(i, n-1, heights, INT_MIN, atlanticVisited); // LAST COLUMN
        }

        // Final Ans

        vector<vector<int>> result;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};