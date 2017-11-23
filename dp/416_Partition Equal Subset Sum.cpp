/*
将一个数组分成两部分，使他们的和相等
就是找子序列使得和是总和的一半嘛，所以是个部分和问题。
一开始用dfs写的，结果超时了，换成dp

dp[i][j]是一个bool数组，示用前i个数能否加和出j。可以优化为一维数组。
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum /= 2;
        bool *dp = new bool[sum + 1];
        memset(dp, 0, sizeof(bool) * (sum + 1));
        dp[0] = true;
        for (auto n : nums) {
            for (int s = sum; s >= n; --s) {
                dp[s] |= dp[s - n];
            }
        }
        return dp[sum];
    }

};