/*
求[0,10^n]之间各个数位数字都不一样的数字的个数
 */
 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[11];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 91;
        for(int i = 3; i <= 10; ++i) {
            dp[i] = dp[i - 1] + (10 - i + 1) * (dp[i - 1] - dp[i - 2]);
        }
        if (n > 10) return dp[10];
        else return dp[n];
    }
};
