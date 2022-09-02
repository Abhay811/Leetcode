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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*>q;
        vector<double> res;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            double s = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                s += temp -> val;
                q.pop();
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
                    
            }
            s /= size;
            res.emplace_back(s);
        }
        return res;
    }
};