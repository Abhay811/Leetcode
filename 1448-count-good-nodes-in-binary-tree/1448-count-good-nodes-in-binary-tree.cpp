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
    int solve(TreeNode* root, int mx)
    {
        if (root == nullptr) return 0;
        if (root -> val >= mx)
            return 1 + solve(root -> left, root -> val) + solve(root -> right, root -> val);
        return solve(root -> left, mx) + solve(root -> right, mx);
    }
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        return solve(root, mx);
    }
};