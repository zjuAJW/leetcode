#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
class Solution {
public:
    int strangePrinter(string s) {
        int dp[105][105];
        auto n = s.size();
        if (!n)
            return 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                dp[j][j + i] = i + 1;
                for (int k = j + 1; k <= j + i; ++k) {
                    auto tmp = dp[j][k - 1] + dp[k][j + i];
                    if (s[k - 1] == s[j + i]) --tmp;
                    dp[j][j + i] = min(dp[j][j + i], tmp);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.strangePrinter("aaabbb") << endl;
}