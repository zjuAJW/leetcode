/*
这题一开始卡了很久，最后的dp数组是一个三维数组
dp[k][i][j]表示在（i，j）点，移动k步之后还没有出棋盘的可能的数量，那么
dp[k][i][j] = sum_n(dp[k - 1][i + dx[n]][j + dy[n]])也就是从该点向8个可能的方向移动后的点，
再移动k-1步之后还在棋盘内的数量。

这题还有一点奇怪的是，为什么dp数组用double不会造成越界呢？因为当K很大的时候,pow(8,K)会非常大，
long long都是存不下的，为什么用double的精度就可以呢？
 */
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int dx[8] = { 1,-1,2,-2,1,-1,2,-2 };
        int dy[8] = { 2,2,1,1,-2,-2,-1,-1 };
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        for (int m = 0; m <= K; ++m) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int n = 0; n < 8; ++n) {
                        if (m == 0) { dp[m][i][j] = 1; continue; }
                        if (isIn(i + dx[n], j + dy[n], N)) {
                            dp[m][i][j] += dp[m - 1][i + dx[n]][j + dy[n]];
                        }
                    }
                }
            }
        }
        return dp[K][r][c] / pow(8,K);
    }

    bool isIn(int x, int y, int N) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
};