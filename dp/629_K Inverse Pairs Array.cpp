class Solution {
public:
    int x = 1000000007;
    int kInversePairs(int n, int k) {
        int dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            dp[i][0] = 1;
        dp[2][1] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % x;
                if (j >= i) {
                    dp[i][j] -= dp[i - 1][j - i];
                    dp[i][j] = (dp[i][j] + x) % x;
                }
            }
        }
        return dp[n][k];
    }
};