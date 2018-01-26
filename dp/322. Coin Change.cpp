/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.


这题一看和背包是很像的，所以按照背包写了一个，可以通过，但是复杂度略高。
参考了一下讨论的答案，dp[n]记录amount = n时的解，然后对于每一个硬币，dp[i] = min(dp[i], dp[i - coins[j]] + 1)
*/

//背包解法
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		auto n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
		for (int i = 0; i < n; ++i) {
			dp[i][0] = 0;
		}
		for (int j = 1; j <= amount; ++j) {
			if (j % coins[0] == 0)
				dp[0][j] = j / coins[0];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= amount; ++j) {
				for (int k = 0; k * coins[i] <= j; ++k) {
					if (dp[i - 1][j - k * coins[i]] != -1) {
						if (dp[i][j] == -1)
							dp[i][j] = dp[i - 1][j - k * coins[i]] + k;
						else
							dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i]] + k);
					}
				}
			}
		}
		return dp[n - 1][amount];
	}
};

//优化DP解法
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		auto n = coins.size();
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (auto coin : coins) {
				if(coin <= i)
					dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};