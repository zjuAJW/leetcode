/*
这道题比Unique Binary Search Trees多的要求是要把每棵树都输出来
递归一下就可以了，一开始以为这样复杂度会比较高，但是还好。
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> nodes;
        if (start == end) {
            nodes.push_back(new TreeNode(start));
            return nodes;
        }
        if (start > end) {
            nodes.push_back(nullptr);
            return nodes;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left;
            vector<TreeNode*> right;
            left = helper(start, i - 1);
            right = helper(i + 1, end);
            for (int m = 0; m < left.size(); ++m) {
                for (int n = 0; n < right.size(); ++n) {
                    TreeNode * t = new TreeNode(i);
                    t->left = left[m];
                    t->right = right[n];
                    nodes.push_back(t);
                }
            }
        }
        return nodes;
    }

};