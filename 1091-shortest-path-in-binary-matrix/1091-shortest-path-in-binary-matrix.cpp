class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        if (n == 1) return  1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
        int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for (int i = 0; i < 8; ++i)
            {
                int x = dx[i], y = dy[i];
                
                if (r + x < 0 || c + y < 0 || r + x >= n || c + y >= n || grid[r + x][c + y] >= 1)
                    continue;
                grid[r + x][c + y] = 1 + grid[r][c];
                if (r + x == n - 1 && c + y == n - 1)
                    return grid[n - 1][n - 1];
                q.push({r + x, c + y});
            }
        }
        return -1;
    }
};