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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                v[i] = temp -> val;
                if (temp -> left != nullptr)
                    q.push(temp -> left);
                if (temp -> right != nullptr)
                    q.push(temp -> right);
                
            }
            res.emplace_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};