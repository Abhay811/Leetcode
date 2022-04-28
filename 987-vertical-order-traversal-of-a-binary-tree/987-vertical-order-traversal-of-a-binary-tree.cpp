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
    void verticalOrder(TreeNode *root)
    {
        if (!root) return;
        map<int, map<int, multiset<int>>> vot;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            TreeNode* temp = t.first;
            int x = t.second.first, y = t.second.second;
            vot[x][y].insert(temp -> val);
            if (temp -> left) q.push({temp -> left, {x - 1, y + 1}});
            if (temp -> right) q.push({temp -> right, {x + 1, y + 1}});
        }
        
        for (auto p : vot)
        {
            vector<int> v;
            for (auto t : p.second)
                v.insert(v.end(), t.second.begin(), t.second.end());
            
            res.emplace_back(v);
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        verticalOrder(root);
        return res;
    }
};