/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (!temp) s.append("#,");
            else s.append(to_string(temp -> val) + ",");
            if (temp) q.push(temp -> left), q.push(temp -> right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        if (str.size() == 0) return nullptr;
        
        stringstream ss(str);
        string s;
        getline(ss, s, ',');
        TreeNode *root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            getline(ss, s, ',');
            if (s == "#") temp -> left = nullptr;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(s));
                temp -> left = leftNode;
                q.push(leftNode);
            }
            getline(ss, s, ',');
            if (s == "#") temp -> right = nullptr;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(s));
                temp -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));