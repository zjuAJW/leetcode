/*
    Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].

这种两个字符串的题，基本dp都是这个套路了吧。。。dp[i][j]表示s1的[0,i]子串和s2[0,j]子串的解
只不过这里这个dp的递推一开始没想明白，其实也很简单。
相等，就不用删除，不相等，就删除其中一个，选结果小的。

*/
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		auto m = s1.size();
		auto n = s2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			dp[i][0] = dp[i - 1][0] + s1[i - 1];
		}
		for (int j = 1; j <= n; ++j) {
			dp[0][j] = dp[0][j - 1] + s2[j - 1];
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
			}
		}
		return dp[m][n];
	}
};