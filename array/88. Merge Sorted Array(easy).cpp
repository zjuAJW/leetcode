/*
两个有序数组，要求将第二个并到第一个中合成一个有序数组
基本的合并操作，merge sort里也常用到
不过这里可以不用开一个新数组，直接从最大值开始填充。题目中保证了num1的空间是足够大的
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1;
		int k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}
		if (j >= 0) {
			while (j >= 0)
				nums1[k--] = nums2[j--];
		}
	}
};