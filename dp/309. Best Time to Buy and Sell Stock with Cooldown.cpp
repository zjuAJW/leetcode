/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

股票题还是按照通用的解法，这里cooldown只需要在买入时考虑前两天前的状态就可以了。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		auto n = prices.size();
		if (n == 0)
			return 0;
		vector<vector<int>> dp(n + 5, vector<int>(2, 0));
		dp[1][0] = 0;
		dp[1][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
			dp[i + 1][1] = max(dp[i][1], dp[i - 1][0] - prices[i]);
		}
		return max(dp[n][0], dp[n][1]);
	}
};