/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void rightView(TreeNode* root, int lvl)
    {
        if (!root) return;
        if (lvl == res.size()) res.emplace_back(root -> val);
        rightView(root -> right, lvl + 1);
        rightView(root -> left, lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return res;
        int lvl = 0;
        rightView(root, lvl);
        return res;
    }
};