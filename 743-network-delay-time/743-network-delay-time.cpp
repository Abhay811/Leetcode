
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = (1 << 30);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < times.size(); i++) graph[times[i][0]].push_back({times[i][1], times[i][2]});
        
        vector<int> dis(n + 1, inf);
        dis[k] = 0;
        pq.push({k, 0});
        while (!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
            for (auto av : graph[u])
            {
                int v = av.first, w = av.second;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pq.emplace(v, dis[v]);
                }
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == inf ? -1 : res;
    }
};