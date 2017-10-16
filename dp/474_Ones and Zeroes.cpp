/*
For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.


这题是个背包问题的变化版本，写法和背包是一样的，这里用了节省空写法，但是要注意在循环的时候要从大到小循环，否则前边的会被更先更新掉。
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int dp[100][100];
		memset(dp, 0, sizeof(dp));
		for (auto s : strs) {
			int num1 = 0, num0 = 0;
			for (auto c : s) {
				if (c == '0') ++num0;
				if (c == '1') ++num1;
			}
			for (int i = m; i >= num0; --i) {
				for (int j = n; j >= num1; --j) {
					dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
				}
			}
		}
		return dp[m][n];
	}
};