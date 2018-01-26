/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

递归解法比较直接一些，好理解，但是复杂度略高

dp解法其实思路和递归是一样的，就是在处理*的时候需要好好想一下，

         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         * 

*/

//递归解法
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p[1] == '*')
			return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0]=='.') && isMatch(s.substr(1), p));
		else
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
};




//dp解法
class Solution {
public:
	bool isMatch(string s, string p) {
		auto n1 = s.size();
		auto n2 = p.size();
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		dp[0][0] = true;
		for (int j = 1; j <= n2; ++j) {
			dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
		}
		for (int i = 1; i <= n1; ++i) {
			for (int j = 1; j <= n2; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				}
				else
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
		return dp[n1][n2];
	}
};