/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

给定一个二阶矩阵，求其中任意一个子矩阵的数字之和

题目的讨论里解法很详细。
很有趣的是这题的DP数组并不是直接存储答案，最后的结果是间接利用dp数组来求取的。
*/
class NumMatrix {
public:
	vector<vector<int>> dp;
	NumMatrix(vector<vector<int>> matrix) {
		int m = matrix.size();
		int n = m > 0 ? matrix[0].size() : 0;
		dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
	}
};