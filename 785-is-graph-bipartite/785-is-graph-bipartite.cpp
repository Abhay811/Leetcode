class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> col(size);
        queue<int> q;
        
        for (int i = 0; i < size; ++i)
        {
            if (col[i]) continue;
            col[i] = 1;
            for (q.push(i); !q.empty(); q.pop())
            {
                int cur = q.front();
                for (auto g : graph[cur])
                {
                    if (!col[g])
                        col[g] = -col[cur], q.push(g);
                    else if (col[g] == col[cur])
                        return false;
                }
            }
        }
        return true;
    }
};