class Solution {
public:
    int minSteps(int n) {
        int dp[1005];
        fill(dp, dp + 1005, 100000);
        dp[0] = dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 2; j <= i; j++) {
                if (i % j == 0) {
                        dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};