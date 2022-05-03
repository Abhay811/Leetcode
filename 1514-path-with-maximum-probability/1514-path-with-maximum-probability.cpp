class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sucProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i)
            graph[edges[i][0]].push_back({edges[i][1], sucProb[i]}),
            graph[edges[i][1]].push_back({edges[i][0], sucProb[i]});
        
        vector<double> dis(n, double(0.0));
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});
        dis[start] = 1.0;
        
        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            double pro = top.first;
            int node = top.second;
            for (auto &t : graph[node])
            {
                if (dis[t.first] < t.second * pro)
                {
                    dis[t.first] = t.second * pro;
                    q.push({dis[t.first], t.first});
                }
            }
        }
        return dis[end];
    }
};