/*
 Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]


一个新数如果可以加入集合的话，那么它一定能被最大的数整除或者能整除最小的数。
知道了这点以后，就是怎么记录结果了，这一点一直没想明白
看了discuss，是用一个parent数组存的，而且程序的实现方式也挺巧妙的
先排序，再从到小来找数，这样可以更方便地存结果。
*/

//参考了discuss
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> parent(n, 0);
        int maxL = 0, index = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
                if (dp[i] > maxL) {
                    maxL = dp[i];
                    index = i;
                }
            }
            
        }
        vector<int> ret;
        for(int i = 0; i < maxL; ++i){
            ret.push_back(nums[index]);
            index = parent[index];
        }
        return ret;
    }
};