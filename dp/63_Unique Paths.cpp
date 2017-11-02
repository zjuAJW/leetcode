/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

迷宫从左上角到右下角共多少种路径（只能向下或者向右）
第二个是在迷宫中加了障碍
很简单的dp
 */

//1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
        }
        return ret[m - 1][n - 1];
    }
};


//2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();
        vector<vector<int>> ret(m + 1, vector<int>(n + 1, 0));
        ret[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                if (obstacleGrid[i - 1][j - 1] == 1)
                    ret[i][j] = 0;
                else
                    ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
        }
        return ret[m][n];
    }
};