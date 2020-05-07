#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    pair<int, int> dfs(TreeNode v, int id, int d, int p = -1)
    {
        if (v.val == id)
        {
            return pair<int, int>(d, p);
        }
        pair<int, int> ret = pair<int, int>(-1, -1);
        if (v.left != nullptr)
        {
            ret = max(ret, dfs(*v.left, id, d + 1, v.val));
        }
        if (v.right != nullptr)
        {
            ret = max(ret, dfs(*v.right, id, d + 1, v.val));
        }
        return ret;
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        auto findX = dfs(*root, x, 0, root->val);
        auto findY = dfs(*root, y, 0, root->val);
        bool ans = findX.first == findY.first && findX.second != findY.second;
        return ans;
    }
};