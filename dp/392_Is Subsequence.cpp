/*
判断一个字符串是不是另一个的子串，可以非连续
水题水题
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        if (s.size() == 0) return true;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[j]) ++j;
            if (j >= s.size()) return true;
        }
        return false;
    }
};