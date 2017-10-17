/*
题目定义了一种串
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

要求从给定串中找到arithmetic的串的数目

其实从头到尾扫一遍统计一下就可以了哈，一开始是这样写的，但是写的有点丑。
参考了一下讨论里的，可以写成dp的形式。
 */

// DP解法
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        auto n = A.size();
        if (n < 3) return 0;
        vector<int>dp(n, 0);
        if (A[2] - A[1] == A[1] - A[0]) dp[2] = 1;
        for (int i = 3; i < n; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

//自己写的
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        auto n = A.size();
        int tmp = 0;
        int sum = 0;
        int dif = 0;
        for (int i = 0; i < n; ++i) {
            if (!tmp) {
                if (i <= n - 3 && A[i + 2] - A[i + 1] == A[i + 1] - A[i]) {
                    dif = A[i + 1] - A[i];
                    ++tmp;
                    sum += tmp;
                    ++i;
                }
            }
            else {
                if (i <= n - 2 && A[i + 1] - A[i] == dif) {
                    ++tmp;
                    sum += tmp;
                }
                else {
                    tmp = 0;
                    --i;
                }
            }
        }
        return sum;
    }
};