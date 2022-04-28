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
    vector<vector<int>> res;
    void zigZag(TreeNode* root)
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while(!q.empty())
        {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; ++i)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.emplace_back(temp -> val);
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
            }
            ltr = !ltr;
            if (ltr) reverse(v.begin(), v.end());
            res.emplace_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return res;
        zigZag(root);
        return res;
    }
};