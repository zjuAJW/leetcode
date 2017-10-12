class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long long dp[51][50][50] = {};
        memset(dp, 0, sizeof(dp));
        for (int ni = 1; ni <= N; ++ni) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    dp[ni][x][y] = ((x - 1 < 0 ? 1 : dp[ni - 1][x - 1][y]) % 1000000007 + (x + 1 >= m ? 1 : dp[ni - 1][x + 1][y]) % 1000000007 + (y - 1 < 0 ? 1 : dp[ni - 1][x][y - 1]) % 1000000007 + (y + 1 >= n ? 1 : dp[ni - 1][x][y + 1]) % 1000000007) % 1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};