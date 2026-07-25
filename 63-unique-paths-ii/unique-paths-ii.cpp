class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // base case
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        // memo
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // move right
        int right = 0;
        // move if safe and not stone
        if(i < m - 1 && obstacleGrid[i+1][j] != 1) {
            right = solve(i + 1, j, obstacleGrid);
        }

        // move down
        int down = 0;
        // move if safe and not stone
        if(j < n - 1 && obstacleGrid[i][j+1] != 1) {
            down = solve(i, j + 1, obstacleGrid);
        }

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // if 1st cell is obstacle
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp.assign(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, obstacleGrid);
    }
};