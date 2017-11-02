/*
求最长上升子序列的个数
基本的最长上升子序列就不用说了，要求个数，那么就再用一个数组记录一下每个位置的个数，然后依旧DP下去就可以了

这破题调了很久，两个数组其实可以合成一个，存一个pair的数组就可以了。
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int ret = 1;
        int max = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = dp[i];
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > tmp) {
                        count[i] = count[j];
                        tmp = dp[i];
                    }
                    else if (dp[i] == tmp) {
                        count[i] += count[j];
                    }
                }
            }
            dp[i] = tmp;
            if (tmp > max) {
                ret = count[i];
                max = tmp;
            }
            else if (tmp == max) {
                ret += count[i];
            }
        }
        return ret;
    }
};