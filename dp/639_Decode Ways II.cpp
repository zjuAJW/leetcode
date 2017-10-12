class Solution {
public:
    long long x = 1000000007;
    int numDecodings(string s) {
        if (s == "0")
            return 0;
        long long dp[100005];
        auto n = s.size();
        dp[0] = 1;
        if (s[0] == '*')
            dp[1] = 9;
        else if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '*') {
                dp[i + 1] = (dp[i] * 9) % x;
                if (s[i - 1] == '1')
                    dp[i + 1] += ((dp[i - 1] * 9) % x);
                else if (s[i - 1] == '2')
                    dp[i + 1] += ((dp[i - 1] * 6) % x);
                else if (s[i - 1] == '*')
                    dp[i + 1] += ((dp[i - 1] * 15) % x);
            }
            else {
                if (s[i] == '0') {
                    if (s[i - 1] == '1' || s[i - 1] == '2')
                        dp[i + 1] = dp[i - 1];
                    else if (s[i - 1] == '*')
                        dp[i + 1] = (dp[i - 1] * 2) % x;
                    else
                        return 0;
                }
                else {
                    dp[i + 1] = dp[i];
                    if (s[i - 1] == '1' || s[i - 1] == '*')
                        dp[i + 1] = (dp[i + 1] + dp[i - 1]) % x;
                    if ((s[i - 1] == '2' || s[i - 1] == '*')&& s[i] >= '1' && s[i] <= '6')
                        dp[i + 1] = (dp[i + 1] + dp[i - 1]) % x;
                }
            }
        }
        return dp[n] % x;
    }
};