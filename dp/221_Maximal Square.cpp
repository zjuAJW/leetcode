/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.


找一个矩阵中的最大正方形
递推式我是想出来了，确实是对的，但是我不知道为什么是这样，凭感觉的。。。
另外，如果不告诉我这道题是dp，我能想到用dp做？
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ret = max(dp[i][j], ret);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ret * ret;
    }
};