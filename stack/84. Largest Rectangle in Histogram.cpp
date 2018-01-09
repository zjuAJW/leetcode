/*
求一个柱状图中最大的矩形面积

暴力的解法就是遍历一遍，复杂度O(n^2)
参考了一些资料，可以优化为O(n)，用了栈，思路还是挺巧妙的
可以参考http://chuansong.me/n/390896436960以及http://blog.csdn.net/yutianzuijin/article/details/52072427
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        auto n = heights.size();
        stack<int> st;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                auto h = heights[st.top()];
                st.pop();
                auto k = st.empty() ? -1 : st.top();
                ret = h * (i - k - 1) > ret ? h * (i - k - 1) : ret;
            }
            st.push(i);
        }
        return ret;
    }
};