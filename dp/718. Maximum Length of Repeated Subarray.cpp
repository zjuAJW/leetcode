/*
求最长公共子串，注意和子序列区别开，这里的子串必须是连续的
思路是最长公共子序列是一样的，只不过在a[i]!=a[j]时的处理不一样。
另外结果是单独存的，而不是在dp数组的最后一个元素里
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        auto m = A.size();
        auto n = B.size();
        int ret = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(dp[i][j], ret);
                }
            }
        }
        return ret;
    }
};