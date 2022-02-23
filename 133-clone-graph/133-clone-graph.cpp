/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (m.find(node) == m.end())
        {
            m[node] = new Node(node -> val, {});
            for (auto it : node -> neighbors)
                m[node] -> neighbors.emplace_back(cloneGraph(it));
        }
        return m[node];
    }
};