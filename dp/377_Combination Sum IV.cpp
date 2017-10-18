/*
题意要求是一个正数数组，问有多少中方式可以加和成target，数字可以重复使用
一开始当作多重和来做的，后来发现，题中要求不同数字的不同排序算是不一样的组合，
例如：[1,2,3], target = 4,可以有7种方式
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

所以改成了以下写法，参考了disscus
 */
class Solution {
public:
    int* dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp = new int[target + 1];
        fill(dp, dp + target + 1, -1);
        dp[0] = 1;
        return helper(nums, target);
    }
    
    int helper(vector<int>& nums, int target) {
        if (dp[target] != -1)
            return dp[target];
        auto n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if(target - nums[i] >= 0)
                ret += helper(nums, target - nums[i]);
        }
        dp[target] = ret;
        return ret;
    }

};