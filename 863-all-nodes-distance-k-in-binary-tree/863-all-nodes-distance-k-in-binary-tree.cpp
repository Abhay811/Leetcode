/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t -> left)
                parent[t -> left] = t, q.push(t -> left);
            if (t -> right)
                parent[t -> right] = t, q.push(t -> right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        
        vis[target] = true;
        int lvl = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (lvl++ == k) break;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* t = q.front();
                q.pop();
                if (t -> left && !vis[t -> left])
                    q.push(t -> left), vis[t -> left] = true;
                if (t -> right && !vis[t -> right])
                    q.push(t -> right), vis[t -> right] = true;
                if (parent[t] && !vis[parent[t]])
                    q.push(parent[t]), vis[parent[t]] = true;
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            res.emplace_back(t -> val);
        }
        return res;
    }
};