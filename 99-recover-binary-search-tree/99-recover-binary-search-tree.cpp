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
        TreeNode* leftTarget = 0, *rightTarget = 0;
    bool leftFound = false, rightFound = false;
    void recoverTree(TreeNode* root) {
        inorder(root); inverseInorder(root);
        swap(leftTarget -> val, rightTarget -> val);
    }
    void inorder (TreeNode* root)
    {
        if (!root) return;
        inorder(root-> left);
        if (!leftFound && (!leftTarget || leftTarget -> val <= root-> val)) leftTarget = root;
        else {leftFound = true; return;}
        inorder(root -> right);
    }
    void inverseInorder(TreeNode* root) {
        if (!root) return;
        inverseInorder(root->right);
        if (!rightFound&&(!rightTarget||rightTarget->val>=root->val)) rightTarget=root;
        else { rightFound=true; return;}
        inverseInorder(root->left);
    }
};