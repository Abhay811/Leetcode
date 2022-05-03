typedef tuple<int, int, int> ti;
class Solution {
public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int, int>>> graph(n);
//         for (auto &f : flights)
//         {
//             graph[f[0]].push_back({f[1], f[2]});
//         }
//         priority_queue<ti, vector<ti>, greater<ti>> pq;
//         pq.emplace(make_tuple(0, src, k + 1));
//         while (!pq.empty())
//         {
//             auto [cost, u, st] = pq.top();
//             pq.pop();
//             if (u == dst) return cost;
//             if (!st) continue;
//             for (auto to : graph[u])
//             {
//                 auto [v, w] = to;
//                 pq.emplace(cost + w, v, st - 1);
//             }
//         }
//         return -1;
//     }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        for (int i = 0; i <= k + 1; i++) dp[i][src] = 0;
        
        for (int i = 1; i <= k + 1; i++)
            for (auto &f : flights)
            {
                int u = f[0], v = f[1], w = f[2];
                if (dp[i - 1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
            }
        return (dp[k + 1][dst] == INT_MAX) ? -1 : dp[k + 1][dst];
    }
};