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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int c = q.size();
            int s = q.front().second;
            int end = q.back().second;
            res = max(res, end - s + 1);
            for (int i = 0; i < c; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                int idx = p.second - s;
                q.pop();
                if (p.first -> left != nullptr)
                    q.push({p.first -> left, (long long) 2 * idx + 1});
                if (p.first -> right != nullptr)
                    q.push({p.first -> right, (long long) 2 * idx + 2});
            }
        }
        return res;
    }
};