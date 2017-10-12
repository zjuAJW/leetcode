/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].


其实题意就是求最多的不重合的区间个数
用贪心法，每次取合法区间中结束时间最早的。
注意由于要找结束时间最早的，所以要按照结束时间来排序。

 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });
        int result = 1;
        int end = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > end) {
                end = pairs[i][1];
                ++result;
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<vector<int>> pairs = { {1,2}, {3,4} };
    cout << s.findLongestChain(pairs);
}