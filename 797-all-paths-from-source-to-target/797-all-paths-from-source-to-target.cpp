class Solution {
public:
    void solve(vector<vector<int>>& graph, int temp, vector<int>& t, vector<vector<int>>& res, vector<int> &vis)
    {
        t.emplace_back(temp);
        if (temp == graph.size() - 1)
        {
            res.emplace_back(t);
            t.pop_back();
            return;
        }
        vis[temp] = 1;
        for (int i = 0; i < graph[temp].size(); ++i)
            if (vis[graph[temp][i]] == 0)
                solve(graph, graph[temp][i], t, res, vis);
        vis[temp] = 0;
        t.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> t;
        int n = graph.size();
        vector<int> vis(n, 0);
        solve(graph, 0, t, res, vis);
        return res;
        
    }
};