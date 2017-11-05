/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

这道题利用了一下set的性质，set是有序的而且不能重复，所以每次从set的begin处拿到最小的数，然后乘2，3，5结果放回去
这样会有很多重复计算。
看了一下discuss里的方法，思路是一样的，它在重复计算这里做了一定的优化
*/
class Solution {
public:
	int nthUglyNumber(int n) {
		set<long long> seq;
		seq.insert(1);
		seq.insert(2);
		seq.insert(3);
		int ret = 0;
		while (!seq.empty()) {
			auto x = *seq.begin();
			seq.erase(seq.begin());
			++ret;
			if (ret == n) return x;
			seq.insert(x * 2);
			seq.insert(x * 3);
			seq.insert(x * 5);
		}
	}
};
