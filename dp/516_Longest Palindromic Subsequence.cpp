/*
    一道最长回文串的变形，区别是回文串可以是不连续的。
    dp[i][j]为i到j字串中最长回文串的长度
    如果s[i] = s[j]，那么dp[i][j] = dp[i + 1][j - 1] + 2，注意是 + 2
    否则，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        auto n = s.size();
        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                if (s[j] == s[j + i])
                    dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
                else
                    dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            }
        }
        return dp[0][n - 1];

    }
};