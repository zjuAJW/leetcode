/*
两人轮流从一个数组的首或者尾拿数字，谁拿的和大谁赢，问第一个拿的玩家会不会获胜。
这里用递归直接写了一下，过了，但是用时很长。
看了一下讨论，可以用dp，dp[i][j]代表[i,j]区间内第一个玩家可以比第二个玩家多拿多少
dp(i, j) = max(nums[j] - dp(i, j-1), nums[i] - dp(i+1, j))
*/

//递归解法
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int sum1 = helper(nums, 0, nums.size() - 1);
		if (sum1 >= sum - sum1)
			return true;
		else
			return false;
	}

	int helper(vector<int>& nums, int i, int j) {
		if (i == j) return nums[i];
		return max(nums[i] + accumulate(nums.begin() + i, nums.begin() + j + 1, 0) - helper(nums, i + 1, j), nums[j] + accumulate(nums.begin() + i, nums.begin() + j + 1, 0) - helper(nums, i, j - 1));
	}
};

//DP解法
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
            }
        }
        return dp[0][n-1] >= 0; // player1 get more score points than player2
    }
};