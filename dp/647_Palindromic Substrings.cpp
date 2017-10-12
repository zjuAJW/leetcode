/*
讨论中给的算法是以每个字符为中心向外扩展，并计数回文串。
自己写的这种算法看起来冗长了一些，但是思路都是一样，遍历每个长度的字符串。
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        bool dp[1005][1005];
        auto n = s.size();
        int result = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            ++result;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                if (j + 1 > j + i - 1) {
                    if (dp[j][j + i] = s[j] == s[j + i])
                        ++result;
                }
                else {
                    if (dp[j][j + i] = dp[j + 1][j + i - 1] && s[j] == s[j + i])
                        ++result;
                }
            }
        }
        return result;
    }
    
};


int main() {
    Solution s;
    cout << s.countSubstrings("aaa");

}