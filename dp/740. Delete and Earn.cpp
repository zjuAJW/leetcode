/*Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

这一题可以转化为213 劫匪的这一题，因为只要选择了某一个值的话，无论这个值重复了多少遍是可以全部被我们拿走的
因次我们先算好每个	 值一共出现的总和，然后只要不拿相邻的值就可以了

*/


class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		vector<int> count(10001, 0);
		for (auto num : nums)
			count[num] += num;
		/*vector<vector<int>> dp(10001, vector<int>(2,0));*/
		int take = 0, skip = 0, skip_ = 0;
		for (int i = 1; i < 10001; i++) {
			skip_ = skip;
			skip = max(take, skip);
			take = skip_ + count[i-1];
		}
		return max(take, skip);
	}
};