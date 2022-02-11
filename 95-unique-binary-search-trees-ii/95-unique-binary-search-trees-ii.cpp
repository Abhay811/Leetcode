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
    vector<TreeNode*> generateDp(int start, int end, vector<vector<vector<TreeNode*>>> &dp) {
        if (start > end) return {nullptr};
        if (dp[start][end].size() != 0) return dp[start][end];
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateDp(start, i - 1, dp);
            vector<TreeNode*> right = generateDp(i + 1, end, dp);
            for (auto ele : left) {
                for (auto e : right) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = ele, root -> right = e;
                    res.push_back(root);
                }
            }
        }
        return dp[start][end] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> 
            dp(n + 1, vector<vector<TreeNode*>> (n + 1, vector<TreeNode*>(0)));
        return generateDp(1, n, dp);
    }
};