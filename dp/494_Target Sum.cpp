/*
题意就是给一个非负整数数组和一个整数S，用数组中的数进行加减运算，求能得到S的方法。
这里用了广搜，需要注意的是0的的情况要特殊对待一下。
*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return dfs(nums, 0, S);
	}

	int dfs(vector<int>& nums, int i, int S) {
		if (i == nums.size() - 1) {
			int tmp = 0;
			if (nums[i] == S) ++tmp;
			if (nums[i] == -S) ++tmp;
			return tmp;
		}

		return dfs(nums, i + 1, S - nums[i]) + dfs(nums, i + 1, S + nums[i]);
	}
};