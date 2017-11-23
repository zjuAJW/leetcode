/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

*/

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		auto n = nums.size();
		vector<int> visited(n, 0);
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k) return false;
		auto target = sum / k;
		return helper(nums, visited, k, 0, 0, target);

	}

	bool helper(vector<int>& nums, vector<int>& visited, int k, int start, int sum, int target) {
		if (k == 1) return true;
		if (sum == target && sum > 0) return helper(nums, visited, k - 1, 0, 0, target);
		for (int i = start; i < nums.size(); ++i) {
			if (!visited[i]) {
				visited[i] = 1;
				if (helper(nums, visited, k, i + 1, sum + nums[i], target)) return true;
				else visited[i] = 0;
			}
		}
		return false;
	}
};
