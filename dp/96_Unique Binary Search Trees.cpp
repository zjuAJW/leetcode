/*
求n个不同整数元素的平衡二叉树的结构一共有多少种。
好像最后还是n^2的复杂度，没看到更好的解法。
就是遍历左右子树从0个元素到n-1个元素的情况，然后累加起来，也比较简单。
 */
class Solution {
public:
    int numTrees(int n) {
        int *dp = new int[n + 1];
        memset(dp, 0, sizeof(int) * (n + 1));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i - 1 - j];
        }
        int ret = dp[n];
        delete[] dp;
        return ret;
    }
};