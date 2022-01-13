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
    TreeNode* sortedArrayToBST(vector<int>& nums, int s, int size)
    {
        if (s > size)
            return nullptr;
        int m = (s + size) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = sortedArrayToBST(nums, s, m - 1);
        root -> right = sortedArrayToBST(nums, m + 1, size);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return (sortedArrayToBST(nums, 0, size -1));
    }
};