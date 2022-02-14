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
    
    int res = INT_MAX;
    TreeNode* prev = nullptr;
    int minDiffInBST(TreeNode* root) {
        if (root == nullptr) return 0;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root -> left);
        if (prev) res = min (res, abs(root -> val - prev -> val));
        prev = root;
        traverse(root -> right);
    }
};