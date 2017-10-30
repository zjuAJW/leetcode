/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

简单的dp解决，区别一下正负号.
当前数字是正时，max_p[i] = max(nums[i] * max_p[i - 1], nums[i]);
当前数字是负时，max_p[i] = max(nums[i] * min_p[i - 1], nums[i]);

优化的话，可以不用数组来存，只存上一个结果就好了。

 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_p(n, 0);
        vector<int> min_p(n, 0);
        max_p[0] = nums[0];
        min_p[0] = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                max_p[i] = max(nums[i] * max_p[i - 1], nums[i]);
                min_p[i] = min(nums[i] * min_p[i - 1], nums[i]);
            }
            else if(nums[i] < 0){
                max_p[i] = max(nums[i] * min_p[i - 1], nums[i]);
                min_p[i] = min(nums[i] * max_p[i - 1], nums[i]);
            }
            else {
                max_p[i] = min_p[i] = 0;
            }
            ret = max(ret, max_p[i]);
        }
        return ret;
    }
};