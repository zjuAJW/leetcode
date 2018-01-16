/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.


股票类的问题，在这个题目的discuss里有一个总结贴，写的还是很好的，可以参考一下
总的思路就是动态规划，其中dp数组为dp[i][k][s], i为第几天，k为几次交易，s为交易之后手上是由股票还是没股票
根据问题的不同，dp数组可以有一些变化，但是上边这个是普适的。
*/


class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		auto n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return max(dp[n - 1][0], dp[n - 1][1]);
	}
};