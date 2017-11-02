/*
最大子列和，不过注意都是负数的情况
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for (auto n : nums) {
            sum += n;
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};