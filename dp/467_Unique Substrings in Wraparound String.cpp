/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

注意题目中要求不计算重复出现的子串
记录以每个字母结尾的的最长连续子串的长度，然后都加起来就可以了。
比如，abcd这个子串，提供了d，cd，bcd，abcd这4个以d结尾的子串。
*/

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		auto n = p.size();
		if (n == 0) return 0;
		int tmp = 1;
		int count[26];
		memset(count, 0, sizeof(count));
		count[p[0] - 'a'] = 1;
		for (int i = 1; i < n; ++i) {
			if (p[i] == p[i - 1] + 1 || (p[i] == 'a' && p[i - 1] == 'z'))
				++tmp;
			else
				tmp = 1;
			count[p[i] - 'a'] = max(count[p[i] - 'a'], tmp);
		}
		return accumulate(count, count + 26, 0);
	}
};