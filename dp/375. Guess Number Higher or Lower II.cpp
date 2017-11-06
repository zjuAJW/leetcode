/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

这题最开始让我想到的是扔鸡蛋那个问题。。。有点像吧
dp的思路其实很简单，对于区间[i,j]，当选取k时，dp[i][j] = k + max(dp[i][k - 1], dp[k + 1][j])
对k进行循环，找到最小的一个，就是dp[i][j]的值
 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i + j <= n; ++i) {
                dp[i][i + j] = (i + i + j) * j / 2;
                for (int k = i; k <= i + j; ++k) {
                    int tmp = max(dp[i][k - 1], dp[k + 1][i + j]);  
                    dp[i][i + j] = min(dp[i][i + j], tmp + k);
                }
            }
        }
        return dp[1][n];
    }
};