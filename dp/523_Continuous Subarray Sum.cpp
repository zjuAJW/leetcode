
/*
这题的思路还是挺神奇的，如果有subarray的和等于k的整数倍，那么nums从头到这个subarry结束
的和对k取余的结果和不加这个subarry的和对k取余的结果是相同的，所以记录前面和对k的余数就可以了
 */



class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int pre = 0, sum = 0, mod = 0;
        set<int> pre_sum;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            mod = k == 0 ? sum : sum % k;
            if (pre_sum.count(mod) != 0) return true;
            pre_sum.insert(pre);
            pre = mod;
        }
        return false;
    }
};