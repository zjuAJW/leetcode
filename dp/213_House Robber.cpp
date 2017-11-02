/*
一个强盗偷东西，房子是连在一起的，不能偷相邻两家，否则会报警，给定每家的钱，问最多能偷到多少钱。
第二个是如果房子是围成一个圈，那么最多能偷到多少钱。

第一个问题相对简单，dp算一下。
第二个问题一开始没想明白，思路就是找一个没有被抢的家断开这个链就好了，而每家只有两种可能，所以选第一个和最后一个断开。
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> v1(n - 1, 0);
        vector<int> v2(n - 1, 0);
        copy(nums.begin(), nums.end() - 1, v1.begin());
        copy(nums.begin() + 1, nums.end(), v2.begin());
        return(max(helper(v1), helper(v2)));
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};