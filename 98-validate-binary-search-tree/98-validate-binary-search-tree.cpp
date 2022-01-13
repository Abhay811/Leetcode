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
    bool isValidBST(TreeNode* root, long long mi, long long mx)
    {
        if (root == nullptr)
            return true;
        if (root -> val <= mi || root -> val >= mx)
            return false;
        return isValidBST(root -> left, mi, root -> val) && isValidBST(root -> right, root -> val, mx);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        long long mx = INT_MAX;
        long long mi = INT_MIN;
        return isValidBST(root, mi - 1, mx + 1);
        
    }
};