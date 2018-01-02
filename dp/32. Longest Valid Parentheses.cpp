/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

找最长的合法括号序列
解法一使用栈间接存储了不能匹配的括号的位置，然后不能匹配的两个括号之间就是能够匹配的，找出最长的就是答案了

解法二是用DP，dp[i]表示以i结束的最长的合法括号序列的长度
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        auto n = s.size();
        stack<int> ss;
        int ret = 0;
        int count = 0;
        for(int i = 0;i < n;++i){
            if (s[i] == '(')
                ss.push(i);
            else {
                if (!ss.empty()) {
                    if (s[ss.top()] == '(')
                        ss.pop();
                    else
                        ss.push(i);
                }
                else
                    ss.push(i);

            }
        }
        if (ss.empty()) ret = n;
        else {
            int a = 0;
            int b = n;
            while (!ss.empty()) {
                a = ss.top();
                ss.pop();
                ret = max(ret, b - a - 1);
                b = a;
            }
            ret = max(ret, b);
        }
        return ret;
    }
};


 int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }