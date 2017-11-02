/*
题意是说，两人轮流从1～N的整数中不放回地取值，和先达到或者超过S的人取胜，问第一个人能不能呢个获胜。

这类两人博弈的题好像都差不多，可以递归地去写，关键在于如何记录状态避免一些重复计算。
这里需要记录的状态有：
1、哪些数用过了
2、还需要拿多少可以获胜
第二个条件和第一个条件其实是相同的，因为总和减去用过的数就是还需要拿多少，所以只需要记录1就可以了。
用bool数组记录数字的使用情况，然后转为int，用map记录该状态下能否获胜。
 */
class Solution {
public:
    map<int, bool> m;
    bool used[25];
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        memset(used, 0, sizeof(used));
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        
        return helper(maxChoosableInteger, desiredTotal);
    }

    bool helper(int max, int desiredTotal) {
        if (desiredTotal <= 0) return false;
        auto key = toInt(used, max);
        if (m.count(key) == 0) {
            for (int i = 1; i <= max; ++i) {
                if (!used[i]) {
                    used[i] = 1;
                    if (!helper(max, desiredTotal - i)) {
                        m[key] = 1;
                        used[i] = 0;
                        return true;
                    }
                    used[i] = 0;
                }
            }
            m[key] = 0;
        }
        return m[key];
    }
    int toInt(bool* used, int max) {
        int ret = 0;
        for (int i = 1; i <= max; ++i) {
            ret <<= 1;
            if (used[i]) ret |= 1;
        }
        return ret;
    }
};