class Solution {
    int fillcheck(vector<vector<int>>& grid, int x, int y, int m, int n)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return 1 + fillcheck(grid, x + 1, y, m, n) + fillcheck(grid, x - 1, y, m, n)
            + fillcheck(grid, x, y + 1, m, n) + fillcheck(grid, x, y - 1, m, n);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int c = 0, res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    res = max (res, fillcheck(grid, i, j, m, n));
        
        return res;
    }
};