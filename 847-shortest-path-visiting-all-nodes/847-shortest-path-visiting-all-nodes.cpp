class Solution {
public:
    class tuple
    {
        public :
        int node;
        int mask;
        int cost;
        tuple(int node, int mask, int cost) 
        {
            this -> node = node;
            this -> mask = mask;
            this -> cost = cost;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple> q;
        set<pair<int, int>> vis;
        int a = (1 << n) - 1;
        for (int i = 0; i < n; ++i)
        {
            int mValue = 1 << i;
            tuple thisNode(i, mValue, 1);
            q.push(thisNode);
            vis.insert({i, mValue});
        
        }
        while (q.empty() == false)
        {
            tuple curr = q.front();
            q.pop();
            if (curr.mask == a)
                return curr.cost - 1;
            for (auto &adj : graph[curr.node])
            {
                int bothVis = curr.mask;
                bothVis = bothVis | (1 << adj);
                tuple ThisNode(adj, bothVis, curr.cost + 1);
                if (vis.find({adj, bothVis}) == vis.end())
                {
                    vis.insert({adj, bothVis});
                    q.push(ThisNode);
                }
            }
        }
        return -1;
    }
};