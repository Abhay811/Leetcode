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
    int m = INT_MIN;
    int maxSum(TreeNode* root) {
        if (!root) return 0;
        int ls = max (0, maxSum(root -> left));
        int rs = max (0, maxSum(root -> right));
        int s = ls + rs + root -> val;
        m = max(m, s);
        return root -> val + max (ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return m;
    }
};