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
    int sum = 0;
    void rangesum(TreeNode *root, int low, int high) {
        if (!root) return;
        if (root -> val >= low && root -> val <= high) sum += root -> val;
        if (root -> left) rangesum(root -> left, low, high);
        if (root -> right) rangesum(root -> right, low, high);
    }
    int inorder(TreeNode *root, int l, int r)
    {
        if (root) {
            inorder(root -> left, l, r);
            if (root -> val >= l && root -> val <= r)
                sum += root -> val;
            inorder(root -> right, l, r);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        // rangesum(root, low, high);
        if (!root) return 0;
        return inorder(root, low, high);
        // return sum;
    }
};